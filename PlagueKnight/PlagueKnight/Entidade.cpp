#include "Entidade.h"

Entidade::Entidade() :body(sf::Vector2f(50.f, 50.f)) {
	obstSize = NULL;
	posX = NULL;
	posY = NULL;
	window = NULL;
}

Entidade::~Entidade() {}