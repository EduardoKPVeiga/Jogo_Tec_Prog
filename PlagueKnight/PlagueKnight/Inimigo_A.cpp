#include "Inimigo_A.h"

namespace Inimigos {
	Inimigo_A::Inimigo_A() {
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Magenta);
		body.setPosition(100.f, 0.f);
	}

	Inimigo_A::Inimigo_A(float x, float y, sf::RenderWindow* w){
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Magenta);
		body.setPosition(x, y);
		this->window = w;
	}

	Inimigo_A::~Inimigo_A() {}
}