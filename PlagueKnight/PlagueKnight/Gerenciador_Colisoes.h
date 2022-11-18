#pragma once
#include "Entidade.h"
#include "Obstaculo.h"
#include "Plataforma.h"
#include "ListaEntidades.h"
#include "Jogador.h"

#include <iostream>

using namespace Jogadores;

class Gerenciador_Colisoes :public Entidade {
private:
    Lista<Obstaculo>* LOs;
    Lista<Inimigo>* ListEnemies;
    Jogador* j1;
public:
    Gerenciador_Colisoes();
    Gerenciador_Colisoes(Lista<Obstaculo>* LOs, Lista<Inimigo>* ListEnemies);
    ~Gerenciador_Colisoes();

    //Usar list STL
    void setLO(Plataforma* obstacle);
    Obstaculo getObstacle(int position) { return *LOs->getItem(position); }
    bool colidiuJogador(sf::RectangleShape body, int direction);
};