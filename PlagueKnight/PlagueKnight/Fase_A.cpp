#include "Fase_A.h"

namespace Fases {
    Fase_A::Fase_A() {
        inicializeElementos(NULL, NULL);
    }

    Fase_A::Fase_A(Jogador* _jogador1, sf::RenderWindow* _window) {
        inicializeElementos(_jogador1, _window);
    }

    Fase_A::~Fase_A() {}

    void Fase_A::inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window) {
        this->window = _window;
        this->jogador1 = _jogador1;

        //gc = new Gerenciador_Colisoes(&(listaEntidades->LOs), &(listaEntidades->LIs), &(listaEntidades->LPs));

        //listaEntidades->LJs.push(jogador1);
        inicializaPlataforma();
        inicializaInimigos(_jogador1, _window);
        inicializaProjeteis();

        /*
        if(listaEntidades.getLength() == 0) {
            cout << "ERRO: listaEntidades vazia na inicializacao." << endl;
        }
        else {
            cout << "Tamanho de listaEntidades: " << listaEntidades.getLength() << "." << endl;
        }
        //*/

        gc->setListaEntidades(&listaEntidades);

        jogador1->setProjetil(bolinha);

        jogador1->setGC(gc);
    }

    void Fase_A::inicializaPlataforma()
    {
        // Plataforma 1º nivel
        for (int i = 0; i < 44; i++)
        {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 25, window);
            listaEntidades.push(plataforma);
        }

        // Plataformas 2º nivel
        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 150, window);
            listaEntidades.push(plataforma);
        }

        for (int i = 0; i < 7; i++) {
            Plataforma* plataforma = new Plataforma((window->getSize().x - (25 * i)), window->getSize().y - 150, window);
            listaEntidades.push(plataforma);
        }

        // Plataforma 3º nivel
        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma(((window->getSize().x / 5) + (25 * i)), window->getSize().y - 275, window);
            listaEntidades.push(plataforma);
        }

        // Plataformas 4º nivel
        for (int i = 0; i < 7; i++) {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 400, window);
            listaEntidades.push(plataforma);
        }

        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma((window->getSize().x - (25 * i)), window->getSize().y - 400, window);
            listaEntidades.push(plataforma);
        }
    }

    void Fase_A::inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window) {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, window->getSize().y - 50, window, jogador1);
        Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
        Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
        Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);

        inimigo1->setAtirador(true);
        inimigo2->setAtirador(true);
        inimigo3->setAtirador(true);

        listaEntidades.push(inimigo1);
        listaEntidades.push(inimigo2);
        listaEntidades.push(inimigo3);
        listaEntidades.push(inimigo4);

        listaInimigos.push(inimigo1);
        listaInimigos.push(inimigo2);
        listaInimigos.push(inimigo3);
        listaInimigos.push(inimigo4);

        qtdInimigos = 4;
    }

    void Fase_A::inicializaProjeteis() {
        bolinha = new Projetil(window);
        //*
        listaEntidades.push(bolinha);
        listaProjeteis.push(bolinha);
        //*/

        // Projeteis de inimigos B
        for (int i = 0; i < 3; i++) {
            Projetil* projetil = new Projetil(window);
            listaEntidades.push(projetil);
            listaProjeteis.push(projetil);

            listaInimigos.getItem(i)->setProjetil(projetil);
        }
    }

    void Fase_A::displayFase() {
        sf::Font font;
        if (!font.loadFromFile("resources/arial.ttf"))
        {
            exit(1);
        }
        sf::Texture texture;
        sf::Text text;

        //plataforma.setWindow(window);

        // Display
        window->clear(sf::Color::Black);

        jogador1->mover();

        //listaEntidades->moveEntities(jogador1->getPosX(), jogador1->getPosY(), jogador1->getDirecaoDisparo());

        // Inimigos atirando
        int j = 0;
        for (int i = 0; i < listaInimigos.getLength(); i++) {
            listaInimigos.getItem(i)->mover(0.f, 0.f, 0.f);
            if (listaInimigos.getItem(i)->getAtirador()) {
                if (listaProjeteis.getLength() <= qtdInimigos) {
                    listaEntidades.getItem(i)->atirar();
                }

                else {
                    cout << "ERRO: quantidade de projeteis insuficiente!" << endl;
                }

                // Movendo projeteis
                listaProjeteis.getItem(j)->mover(listaInimigos.getItem(i)->getPosX(), listaInimigos.getItem(i)->getPosY(), listaInimigos.getItem(i)->getDirecaoDisparo());
                j++;
            }
        }

        // Desenhando as entidades
        for (int i = 0; i < listaEntidades.getLength(); i++) {
            listaEntidades.getItem(i)->draw();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            jogador1->atirar();

        //bolinha->mover(jogador1->getPosX(), jogador1->getPosY(), jogador1->getDirecaoDisparo());

        jogador1->draw();
        //bolinha->draw();
        
        //listaEntidades->drawEntities(window);

        //this->desenhaPlataforma();

        // Show player's life
        text.setFont(font);
        text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(qtdInimigos));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window->draw(text);
    }
}