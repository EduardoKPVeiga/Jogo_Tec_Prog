#include "Entidade.h"
#include "Gerenciador_Colisoes.h"

Entidade::Entidade() :body(sf::Vector2f(25.f, 25.f)) {
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

float Entidade::getPosX() {
	return body.getPosition().x;
}

float Entidade::getPosY() {
	return body.getPosition().y;
}
