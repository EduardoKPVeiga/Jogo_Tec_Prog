#pragma once

#include "Entidade.h"
#include "Obstaculo.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Lista.h"
#include "Elemento.h"

#include <math.h>
#include <iostream>

using namespace Jogadores;
using namespace Inimigos;

class Gerenciador_Colisoes :public Entidade {
private:
    Lista<Entidade>* listaEntidades;
    Lista<Inimigo>* listaInimigos;
    Lista<Projetil>* listaProjeteis;

    //Lista<Obstaculo>* LOs;
    //Lista<Projetil>* listProjetil;


public:
    Gerenciador_Colisoes();
    Gerenciador_Colisoes(Lista<Entidade>* _listaEntidades);
    Gerenciador_Colisoes(Lista<Entidade>* _listaEntidades, Lista<Inimigo>* _listaInimigos);
    //Gerenciador_Colisoes(Lista<Obstaculo>* _LOs, Lista<Inimigo>* _ListEnemies, Lista<Projetil>* _listProjetil);
    ~Gerenciador_Colisoes();
    //void inicializar(Lista<Obstaculo>* _LOs, Lista<Inimigo>* _ListEnemies, Lista<Projetil>* _listProjetil);
    void inicializar(Lista<Entidade>* _listaEntidades, Lista<Inimigo>* _listaInimigos);
    //void setLO(Plataforma* obstacle);
    //Obstaculo getObstacle(int position) { return *LOs->getItem(position); }
    bool colidiuJogador(sf::RectangleShape _body, int direction, float _velX);
    bool colidiuProjetilInimigo(sf::RectangleShape _bodyProjetil, sf::RectangleShape _bodyJogador, int _direcaoDisparo, float _velX);
    bool colidiuProjetilJogador(sf::RectangleShape _bodyProjetil, int _direcaoDisparo, float _velX);
    void setListaEntidades(Lista<Entidade>* _listaEntidades);
    Lista<Entidade>* getListaEntidades();
    void setListaInimigos(Lista<Inimigo>* _listaInimigos);
    void setListaProjeteis(Lista<Projetil>* _listaProjeteis);
};