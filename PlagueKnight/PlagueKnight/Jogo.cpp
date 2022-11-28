#include "Jogo.h"

Jogo::Jogo() :
    window(sf::VideoMode(float(1100 / RESOLUTION_X), float(720 / RESOLUTION_Y)), "Plague Knight", sf::Style::Close)
{   
    //opcao = Opcao::MENU;
    jogador.setWindow(&window);
    jogador.setBodyPosition(50.f, window.getSize().y - 100.f);
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

            if (fase1->getFaseAtiva()) {
                fase1->displayFase();
            }

            else if (!fase1->getFaseAtiva() && jogador.getVidas() == 0) {
                option = Options::MENU;
                menu.pushVetorPontos(jogador.getPontos());
                jogador.reviver();
                delete fase1;
                fase1 = NULL;
            }

            else if (!fase1->getFaseAtiva() && jogador.getVidas() != 0) {
                option = Options::LEVEL_B;
                menu.pushVetorPontos(jogador.getPontos());
                jogador.setBodyPosition(50.f, window.getSize().y - 100.f);
                delete fase1;
                fase1 = NULL;
            }
        }

        else if(option == Options::LEVEL_B) {
            if (!fase2) {
                fase2 = new Fase_B(&jogador, &window);
            }

            if (fase2->getFaseAtiva()) {
                fase2->displayFase();
            }

            else if (!fase2->getFaseAtiva()) {
                option = Options::MENU;
                menu.pushVetorPontos(jogador.getPontos());
                jogador.setBodyPosition(50.f, window.getSize().y - 100.f);
                jogador.reviver();
                delete fase2;
                fase2 = NULL;
            }
        }
        
        window.display();
    }
}
