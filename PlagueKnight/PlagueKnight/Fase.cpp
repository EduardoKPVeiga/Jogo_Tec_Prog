#include "Fase.h"

namespace Fases {
    Fase::Fase() {
        jogador1 = NULL;
        window = NULL;
        listaEntidades = NULL;
    }

    Fase::Fase(Jogador* jogador1, sf::RenderWindow* window) {
        this->window = window;
        this->jogador1 = jogador1;

        listaEntidades = new ListaEntidades();
        inicializeElementos();

        inicializaPlataforma();
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

        // Show enemies
        listaEntidades->drawEntities(window);
        listaEntidades->moveEntities();

        //desenhaPlataforma();

        // Show player's life
        text.setFont(font);
        text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(listaEntidades->LIs.getLength()));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window->draw(text);
    }

    void Fase::inicializeElementos() {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, 0.f, window);
        Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), (360.f / RESOLUTION_Y), window);
        Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), 0.f, window);
        Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), (20.f / RESOLUTION_Y), window);

        listaEntidades->LIs.push(inimigo1);
        listaEntidades->LIs.push(inimigo2);
        listaEntidades->LIs.push(inimigo3);
        listaEntidades->LIs.push(inimigo4);
    }

    void Fase::desenhaPlataforma() {
        for (int i = 0; i < LO.getLength(); i++)
        {
            LO.getItem(i)->draw();
        }


    }
    void Fase::inicializaPlataforma()
    {
        Plataforma* plataforma = new Plataforma();
        for (float  i = window->getSize().x / plataforma->getBodySize(); i < window->getSize().x; i++)
        {
            Plataforma* plataforma = new Plataforma();
            plataforma->setBodyPosition(window->getSize().y- plataforma->getBodySize(), i * plataforma->getBodySize());
            LO.push(plataforma);
            
        }
        for (int i = 0; i < LO.getLength(); i++)
        {
            //cout << (LOgetItem(i)->getBodySize()) << endl;
        }

    }
}