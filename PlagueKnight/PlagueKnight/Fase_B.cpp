#include "Fase_B.h"

namespace Fases {
    Fase_B::Fase_B() {
        inicializeElementos(NULL, NULL);
    }

    Fase_B::Fase_B(Jogador* _jogador1, sf::RenderWindow* _window) {
        inicializeElementos(_jogador1, _window);
    }

    Fase_B::~Fase_B() {}

    void Fase_B::inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window) {
        this->window = _window;
        this->jogador1 = _jogador1;

        //gc = new Gerenciador_Colisoes(&(listaEntidades->LOs), &(listaEntidades->LIs), &(listaEntidades->LPs));
        gc->setListaEntidades(&listaEntidades);

        //listaEntidades->LJs.push(jogador1);
        inicializaPlataforma();
        inicializaInimigos(_jogador1, _window);
        inicializaProjeteis();

        jogador1->setProjetil(bolinha);

        jogador1->setGC(gc);
    }

    void Fase_B::inicializaPlataforma() {
        // Plataforma 1º nivel
        for (int i = 0; i < 44; i++)
        {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 25, window);
            listaEntidades.push(plataforma);
        }
    }

    void Fase_B::inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window) {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, 0.f, window, jogador1);
        Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), window->getSize().y - 25, window, jogador1);
        Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), window->getSize().y - 25, window, jogador1);
        Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), window->getSize().y - 25, window, jogador1);

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

    void Fase_B::inicializaProjeteis() {
        bolinha = new Projetil(window);
        listaEntidades.push(bolinha);

        // Projeteis de inimigos B
        for (int i = 0; i < 3; i++) {
            Projetil* projetil = new Projetil(window);
            listaEntidades.push(projetil);
            listaProjeteis.push(projetil);

            listaInimigos.getItem(i)->setProjetil(projetil);
        }
    }

    void Fase_B::displayFase() {
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

        int _qtdInimigos = 0;
        for (int i = 0; i < listaEntidades.getLength(); i++) {
            // Entidades se movendo
            listaEntidades.getItem(i)->mover(jogador1->getPosX(), jogador1->getPosY(), jogador1->getDirecaoDisparo());

            // Inimigos atirando
            if (listaEntidades.getItem(i)->getAtirador()) {
                if (_qtdInimigos <= qtdInimigos) {
                    listaEntidades.getItem(i)->atirar();
                    _qtdInimigos++;
                }

                else {
                    cout << "ERRO: quantidade de projeteis insuficiente!" << endl;
                }
            }

            // Desenhando as entidades
            listaEntidades.getItem(i)->draw();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            jogador1->atirar();

        jogador1->draw();

        //listaEntidades->drawEntities(window);

        //this->desenhaPlataforma();

        // Show player's life
        text.setFont(font);
        text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(qtdInimigos));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window->draw(text);
    }
    /*
    void Fase_A::desenhaPlataforma() {
        for (int i = 0; i < LO.getLength(); i++)
        {
            LO.getItem(i)->draw();
        }
    }
    //*/
}