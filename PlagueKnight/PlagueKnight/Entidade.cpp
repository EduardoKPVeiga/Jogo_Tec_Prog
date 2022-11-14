#include "Entidade.h"

Entidade::Entidade() :body(sf::Vector2f(50.f, 50.f)) {
	obstSize = NULL;
	posX = NULL;
	posY = NULL;
	window = NULL;
}

Entidade::~Entidade() {}

void Entidade::receberGravidade(bool empuxo)
{
	if (!empuxo)
	{
		this->body.move(sf::Vector2f(0.0f, gravidade));
	}
	else
	{
		this->body.move(sf::Vector2f(0.0f, gravidade-gravidade));
	}
}
