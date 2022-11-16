#include "Inimigo_A.h"

namespace Inimigos {
	Inimigo_A::Inimigo_A() {
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Magenta);
		body.setPosition(100.f, 0.f);
		atirar();
	}

	Inimigo_A::Inimigo_A(float x, float y, sf::RenderWindow* w) {
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Magenta);
		body.setPosition(x, y);
		this->window = w;
		atirar();
	}

	Inimigo_A::~Inimigo_A() {}

	void Inimigo_A::atirar() {//*
		if (fabs((float)flecha.getPosition().x - body.getPosition().x) > 1000 && fabs(body.getPosition().x - pJogador->getPosX()) < 100000) {
			flecha.setPosition(body.getPosition().x, body.getPosition().y + 50);
			flecha.setFillColor(sf::Color::Magenta);

		}
		window->draw(flecha);
		if (flecha_colisao.intersects(pJogador->getBodyGlobalBounds())) {

			flecha.setPosition(flecha.getPosition().x, 8000);
		}
		//*/
	}
}