#include "Fase_A.h"

namespace Fases {
    Fase_A::Fase_A() {
        inicializeElementos(NULL, NULL);
    }

    Fase_A::Fase_A(Jogador* _jogador1, sf::RenderWindow* _window) {
        inicializeElementos(_jogador1, _window);
    }

    Fase_A::~Fase_A() {}

    void Fase_A::displayFase() {
        sf::Font font;
        if (!font.loadFromFile("resources/arial.ttf"))
        {
            exit(1);
        }
        sf::Texture texture;
        sf::Text text;

        //plataforma.setWindow(window);

        jogador1->mover();

        // Display
        window->clear(sf::Color::Black);

        // Show player
        jogador1->draw();

        listaEntidades->moveEntities(jogador1->getPosX(), jogador1->getPosY(), jogador1->getDirecaoDisparo());

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            jogador1->atirar(bolinha);

        listaEntidades->drawEntities(window);

        this->desenhaPlataforma();

        // Show player's life
        text.setFont(font);
        text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(listaEntidades->LIs.getLength()));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window->draw(text);
    }

    void Fase_A::inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window) {
        this->window = _window;
        this->jogador1 = _jogador1;

        gc = new Gerenciador_Colisoes(&LO, &ListEnemies, &listProjetil);
        jogador1->setGC(gc);
        listaEntidades = new ListaEntidades();

        //listaEntidades->LJs.push(jogador1);
        inicializaPlataforma();
        inicializaInimigos(_jogador1, _window);
        inicializaProjeteis();

    }

    void Fase_A::inicializaPlataforma()
    {
        // Plataforma 1º nivel
        for (int i = 0; i < 44; i++)
        {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 25, window);
            LO.push(plataforma);
        }

        // Plataformas 2º nivel
        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 150, window);
            LO.push(plataforma);
        }

        for (int i = 0; i < 7; i++) {
            Plataforma* plataforma = new Plataforma((window->getSize().x - (25 * i)), window->getSize().y - 150, window);
            LO.push(plataforma);
        }

        // Plataforma 3º nivel
        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma(((window->getSize().x / 5) + (25 * i)), window->getSize().y - 275, window);
            LO.push(plataforma);
        }

        // Plataformas 4º nivel
        for (int i = 0; i < 7; i++) {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 400, window);
            LO.push(plataforma);
        }

        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma((window->getSize().x - (25 * i)), window->getSize().y - 400, window);
            LO.push(plataforma);
        }

        // Plataforma 1º nivel
        for (int i = 0; i < 44; i++)
        {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 25, window);
            LO.push(plataforma);
        }
    }

    void Fase_A::inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window) {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, 0.f, window, jogador1);
        Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), (360.f / RESOLUTION_Y), window, jogador1);
        Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), 0.f, window, jogador1);
        Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), (20.f / RESOLUTION_Y), window, jogador1);

        listaEntidades->LIs.push(inimigo1);
        listaEntidades->LIs.push(inimigo2);
        listaEntidades->LIs.push(inimigo3);
        listaEntidades->LIs.push(inimigo4);
    }

    void Fase_A::inicializaProjeteis() {
        bolinha = new Projetil(window);
        listaEntidades->LPs.push(bolinha);
    }

    void Fase_A::desenhaPlataforma() {
        for (int i = 0; i < LO.getLength(); i++)
        {
            LO.getItem(i)->draw();
        }
    }
}