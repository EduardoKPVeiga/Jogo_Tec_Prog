#include "Jogo.h"

Jogo::Jogo() :
    window(sf::VideoMode(1100, 720), "Swamp Bros", sf::Style::Close)
{
//    opcao = Opcao::MENU;
//    player.setWindow(&window);
    executar();
}
Jogo::~Jogo() { }

void Jogo::executar()
{

    while (window.isOpen())
    {
        window.setFramerateLimit(90);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        /*
        if (option == Options::MENU)
        {
            //Colocar endereco na construtora
            menu.select_options(&option, &window);
        }
        else if (option == Options::LEVEL)
        {

            level->display_level();
        }
        */
        window.display();
    }
}
