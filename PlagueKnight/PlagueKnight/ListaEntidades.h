#pragma once
#include "Lista.h"
#include "Entidade.h"
#include "Inimigo.h"

using namespace Inimigos;

class ListaEntidades {
public:
	ListaEntidades();
	~ListaEntidades();
	Lista<Inimigo> LIs;
	void drawEntities(sf::RenderWindow* window);
	void moveEntities();
};

