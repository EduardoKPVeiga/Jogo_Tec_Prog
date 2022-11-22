#include "Fase.h"

namespace Fases {
    Fase::Fase() {
        jogador1 = NULL;
        bolinha = NULL;
        window = NULL;
        listaEntidades = NULL;
        gc = NULL;
    }

    Fase::Fase(Jogador* jogador1, sf::RenderWindow* window) {
        this->window = window;
        this->jogador1 = jogador1;

        inicializaPlataforma();
        gc = new Gerenciador_Colisoes(&LO,&ListEnemies, &listProjetil);
        jogador1->setGC(gc);
        listaEntidades = new ListaEntidades();
        inicializeElementos();
    }


    Fase::~Fase() {}

    void Fase::displayFase() {
        sf::Font font;
        if (!font.loadFromFile("resources/arial.ttf"))
        {
            exit(1);
        }
        sf::Texture texture;
        sf::Text text;

        //plataforma.setWindow(window);

        // Logic

        jogador1->mover();

        // Display
        window->clear(sf::Color::Black);

        // Show player
        jogador1->draw();

        listaEntidades->moveEntities(jogador1->getPosX(), jogador1->getPosY(), jogador1->getDirecaoDisparo());

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            jogador1->atirar(bolinha);

        listaEntidades->drawEntities(window);

        desenhaPlataforma();

        // Show player's life
        text.setFont(font);
        text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(listaEntidades->LIs.getLength()));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window->draw(text);
    }

    void Fase::inicializeElementos() {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, 0.f, window, jogador1);
        Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), (360.f / RESOLUTION_Y), window, jogador1);
        Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), 0.f, window, jogador1);
        Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), (20.f / RESOLUTION_Y), window, jogador1);
        bolinha = new Projetil(window);

        listaEntidades->LIs.push(inimigo1);
        listaEntidades->LIs.push(inimigo2);
        listaEntidades->LIs.push(inimigo3);
        listaEntidades->LIs.push(inimigo4);
        listaEntidades->LPs.push(bolinha);
        //listaEntidades->LJs.push(jogador1);

    }

    void Fase::desenhaPlataforma() {
        for (int i = 0; i < LO.getLength(); i++)
        {
            LO.getItem(i)->draw();
        }
    }
    void Fase::inicializaPlataforma()
    {
        // Plataformas 1º nivel
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
        for (int i = 0; i < 15; i++) {
            Plataforma* plataforma = new Plataforma(((window->getSize().x / 2) - (25 * i)), window->getSize().y - 275, window);
            LO.push(plataforma);
        }

        // Plataforma 4º nivel
        for (int i = 0; i < 7; i++) {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 400, window);
            LO.push(plataforma);
        }

        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma((window->getSize().x - (25 * i)), window->getSize().y - 400, window);
            LO.push(plataforma);
        }
    }
}