#include "Entidade.h"

Entidade::Entidade() :body(sf::Vector2f(50.f, 50.f)) {
	inicializa(0, 0, 0, 0);
}

Entidade::~Entidade() {}

void Entidade::inicializa(float _posX, float _posY, float _obstSize, sf::RenderWindow* _window) {
	obstSize = _obstSize;
	this->window = _window;
	posX = _posX;
	posY = _posY;
	textura = new sf::Texture;
}

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
	return posX;
}

float Entidade::getPosY() {
	return posY;
}

void Entidade::setDanoso(bool _danoso) {
	danoso = _danoso;
}

bool Entidade::getDanoso() {
	return danoso;
}