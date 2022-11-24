#pragma once
#include <iterator>
#include <SFML/Graphics.hpp>
#include <string>

#include "Fase.h"
#include "Fase_A.h"
#include "Fase_B.h"
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
    Fase_A* fase1;
    Fase_B* fase2;

public:
    Jogo();
    ~Jogo();
    void executar();
};

