#include "Jogo.h"

Jogo::Jogo() :
    window(sf::VideoMode(float(1100 / RESOLUTION_X), float(720 / RESOLUTION_Y)), "Plague Knight", sf::Style::Close)
{   
    //opcao = Opcao::MENU;
    jogador.setWindow(&window);
    executar();
}
Jogo::~Jogo() { }

void Jogo::executar() {

    while (window.isOpen()) {
        window.setFramerateLimit(90);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        
        if (option == Options::MENU) {
            //Colocar endereco na construtora
            menu.select_options(&option, &window);
        }

        else if (option == Options::LEVEL_A) {
            if (!fase1) {
                fase1 = new Fase_A(&jogador, &window);
            }

            fase1->displayFase();
        }

        else if(option == Options::LEVEL_B) {
            if (!fase2) {
                fase2 = new Fase_B(&jogador, &window);
            }

            fase2->displayFase();
        }
        
        window.display();
    }
}
