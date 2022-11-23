#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

//Remover render
void ListaEntidades::drawEntities(sf::RenderWindow* window) {
	/*
	for (int i = 0; i < LIs.getLength(); i++) {
		LIs.getItem(i)->draw();
	}

	for (int i = 0; i < LPs.getLength(); i++) {
		LPs.getItem(i)->draw();
	}

	for (int i = 0; i < LOs.getLength(); i++) {
		LOs.getItem(i)->draw();
	}
	//*/
	

	/*
	for (int i = 0; i < LJs.getLength(); i++) {
		LJs.getItem(i)->draw();
	}
	//*/
}

void ListaEntidades::moveEntities(float _posX, float _posY, int _direcao) {
	/*
	for (int i = 0; i < LIs.getLength(); i++) {
		LIs.getItem(i)->mover();
	}

	for (int i = 0; i < LPs.getLength(); i++) {
		LPs.getItem(i)->mover(_posX, _posY, _direcao);
	}
	//*/

	/*
	for (int i = 0; i < LJs.getLength(); i++) {
		LJs.getItem(i)->mover();
	}
	//*/
}
