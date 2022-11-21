#pragma once
#include <iterator>
#include <SFML/Graphics.hpp>
#include <string>

#include "Fase.h"
#include "Menu.h"
#include "Jogador.h"
#include "Options.h"
#include "Resolucao.h"

using namespace Fases;
using namespace Jogadores;

class Jogo {
private:
    Options option;
    Menu menu;
    sf::RenderWindow window;
    Jogador jogador;
    Fase* fase = new Fase(&jogador, &window);
public:
    Jogo();
    ~Jogo();
    void executar();
};

