#include "Plataforma.h"

Plataforma::Plataforma(float x, float y, sf::RenderWindow* w) {
	body.setPosition(x, y);
	body.setFillColor(sf::Color::White);
	this->window = w;
}

Plataforma::~Plataforma() {}
