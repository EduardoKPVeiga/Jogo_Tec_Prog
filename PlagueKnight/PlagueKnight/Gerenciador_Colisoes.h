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
    Lista<Plataforma> LO;
    Plataforma* plataforma;
public:
    Gerenciador_Colisoes();
    ~Gerenciador_Colisoes();

    //Usar list STL
    void setLO(Plataforma* obstacle);
    Plataforma getObstacle(int position) { return *LO.getItem(position); }
    void verify_collisions(Personagem* person, int direction);
};