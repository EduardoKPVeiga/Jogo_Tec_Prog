#pragma once
#include "Lista.h"
#include "Entidade.h"
#include "Inimigo.h"
#include "Jogador.h"

using namespace Inimigos;

class ListaEntidades {
public:
	ListaEntidades();
	~ListaEntidades();
	Lista<Inimigo> LIs;
	Lista<Projetil> LPs;
	//Lista<Jogador> LJs;
	void drawEntities(sf::RenderWindow* window);
	void moveEntities(float _posX, float _posY, int _direcao);
};

