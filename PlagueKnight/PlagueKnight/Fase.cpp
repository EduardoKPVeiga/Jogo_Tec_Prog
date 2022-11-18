#include "Fase.h"
#include <cmath>
namespace Fases {
    Fase::Fase() {
        jogador1 = NULL;
        window = NULL;
        listaEntidades = NULL;
    }

    Fase::Fase(Jogador* jogador1, sf::RenderWindow* window) {
        this->window = window;
        this->jogador1 = jogador1;

        inicializaPlataforma();
        gc = new Gerenciador_Colisoes(&LO,&ListEnemies);
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

        // Show enemies
        listaEntidades->drawEntities(window);
        listaEntidades->moveEntities();

        desenhaPlataforma();



        // Show player's life
        text.setFont(font);
        text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(listaEntidades->LIs.getLength()));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window->draw(text);
    }

    void Fase::inicializeElementos() {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, 0.f, window);
        Inimigo_B* inimigo2 = new Inimigo_B(650.f, 360.f, window);
        Inimigo_B* inimigo3 = new Inimigo_B(400.f, 0.f, window);
        Inimigo_A* inimigo4 = new Inimigo_A(10.f, 20.f, window);

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
        
        for (int i = 0; i < 22; i++)
        {
            Plataforma* plataforma = new Plataforma(50 * i, window->getSize().y-50, window);
            LO.push(plataforma);
            
        }

    }
}