#include "Inimigo_A.h"

namespace Inimigos {
	Inimigo_A::Inimigo_A() {
		inicializar(NULL, NULL, NULL, NULL);
	}

	Inimigo_A::Inimigo_A(float x, float y, sf::RenderWindow* w){
		inicializar(x, y, w, NULL);
	}

	Inimigo_A::Inimigo_A(float x, float y, sf::RenderWindow* w, Jogador* _jogador) {
		inicializar(x, y, w, _jogador);
	}

	Inimigo_A::~Inimigo_A() {}

	void Inimigo_A::inicializar(float _x, float _y, sf::RenderWindow* _w, Jogador* _jogador) {
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Magenta);
		body.setPosition(_x, _y);
		this->window = _w;
		this->jogador = _jogador;
		atirador = true;
	}
}