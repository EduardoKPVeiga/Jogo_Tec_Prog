#include "Inimigo_A.h"

namespace Inimigos {
	Inimigo_A::Inimigo_A() {
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Magenta);
		body.setPosition(100.f, 0.f);
		//bolinha.setBodyPosition(this->getPosX(), this->getPosY());
		//bolinha.setProjetilAtivo(false);
	}

	Inimigo_A::Inimigo_A(float x, float y, sf::RenderWindow* w) {
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Magenta);
		body.setPosition(x, y);
		this->window = w;
	}

	Inimigo_A::~Inimigo_A() {}

	/*
	void Inimigo_A::atirar() {
		if (!(bolinha.getProjetilAtivo())) { // Se a bolinha nao foi atirada
			if (direcao == 0)
				direcaoDisparo = -1;
			else if (direcao == 1)
				direcaoDisparo = 1;

			bolinha.setProjetilAtivo(true);
		}
		
		bolinha.moverProjetil(this->getPosY(), direcaoDisparo);
		
	}
	*/
}