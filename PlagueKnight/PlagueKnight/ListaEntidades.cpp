#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

//Remover render
void ListaEntidades::drawEntities(sf::RenderWindow* window) {
	for (int i = 0; i < LIs.getLength(); i++) {
		LIs.getItem(i)->draw();
	}
}

void ListaEntidades::moveEntities() {
	for (int i = 0; i < LIs.getLength(); i++) {
		LIs.getItem(i)->move();
	}
}
