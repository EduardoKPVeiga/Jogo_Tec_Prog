#include "Menu.h"

Menu::Menu() {
    options_str.push_back("Level A");
    options_str.push_back("Level B");
}

Menu::~Menu() { }


void Menu::select_options(Options* option, sf::RenderWindow* window) {
    sf::Font font;

    if (!font.loadFromFile("resources/arial.ttf")) {
        exit(1);
    }

    int j = 0;
    sf::Text text;
    for (int i = 0; i < options_str.size(); i++) {
        text.setFont(font);
        text.setString(options_str[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition((500.0 / RESOLUTION_X), ((250 + (50 * i)) / RESOLUTION_Y));
        j = i;
        window->draw(text);
    }

    j++;
    for (int i = 0; i < 5; i++) {
        text.setFont(font);
        text.setString(std::to_string(i + 1) + "º lugar: " + std::to_string(vetorPontos[i]) + " pontos");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition((430.0 / RESOLUTION_X), ((250 + (50 * (j + i))) / RESOLUTION_Y));

        window->draw(text);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= (900 / RESOLUTION_X) &&
        sf::Mouse::getPosition().x <= (1000.0 / RESOLUTION_X) && sf::Mouse::getPosition().y >= (490 / RESOLUTION_Y) &&
        sf::Mouse::getPosition().y <= (510 / RESOLUTION_Y)) {

        window->clear(sf::Color::Black);
        *option = Options::LEVEL_A;
    }

    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >= (900 / RESOLUTION_X) &&
        sf::Mouse::getPosition().x <= (1000.0 / RESOLUTION_X) && sf::Mouse::getPosition().y >= (530 / RESOLUTION_Y) &&
        sf::Mouse::getPosition().y <= (550 / RESOLUTION_Y)) {

        window->clear(sf::Color::Black);
        *option = Options::LEVEL_B;
    }
}


