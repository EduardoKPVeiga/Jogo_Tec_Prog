#include "Inimigo_C.h"

namespace Inimigos {
	Inimigo_C::Inimigo_C() {
		inicializar(NULL, NULL, NULL, NULL);
	}

	Inimigo_C::Inimigo_C(float x, float y, sf::RenderWindow* w) {
		inicializar(x, y, w, NULL);
	}

	Inimigo_C::Inimigo_C(float x, float y, sf::RenderWindow* w, Jogador* _jogador) {
		inicializar(x, y, w, _jogador);
	}

	Inimigo_C::~Inimigo_C() {}

	void Inimigo_C::inicializar(float _x, float _y, sf::RenderWindow* _w, Jogador* _jogador) {
		this->setVelocidade(10.000022f);
		this->setFlyingSpeed(20.000055f);
		body.setFillColor(sf::Color::Yellow);
		body.setPosition(_x, _y);
		this->window = _w;
		this->jogador = _jogador;
		atirador = false;
		empuxo = true;
		num_vidas = 3;
	}
}