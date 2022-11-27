#pragma once
#include "Entidade.h"
#include "Obstaculo.h"
#include "Plataforma.h"
//#include "ListaEntidades.h"
#include "Jogador.h"
#include "Lista.h"
#include "Elemento.h"

#include <math.h>
#include <iostream>

using namespace Jogadores;

class Gerenciador_Colisoes :public Entidade {
private:
    Lista<Entidade>* listaEntidades;
    /*
    Lista<Obstaculo>* LOs;
    Lista<Inimigo>* ListEnemies;
    Lista<Projetil>* listProjetil;
    //*/
    Jogador* j1;
public:
    Gerenciador_Colisoes();
    Gerenciador_Colisoes(Lista<Entidade>* _listaEntidades);
    //Gerenciador_Colisoes(Lista<Obstaculo>* _LOs, Lista<Inimigo>* _ListEnemies, Lista<Projetil>* _listProjetil);
    ~Gerenciador_Colisoes();
    //void inicializar(Lista<Obstaculo>* _LOs, Lista<Inimigo>* _ListEnemies, Lista<Projetil>* _listProjetil);
    void inicializar(Lista<Entidade>* _listaEntidades);
    //void setLO(Plataforma* obstacle);
    //Obstaculo getObstacle(int position) { return *LOs->getItem(position); }
    bool colidiuJogador(sf::RectangleShape body, int direction, float _velX);
    void setListaEntidades(Lista<Entidade>* _listaEntidades);
    Lista<Entidade>* getListaEntidades();
};