#include "Inimigo_B.h"

namespace Inimigos {
	Inimigo_B::Inimigo_B() {
		inicializar(NULL, NULL, NULL, NULL);
	}

	Inimigo_B::~Inimigo_B() {}

	Inimigo_B::Inimigo_B(float x, float y, sf::RenderWindow* w) {
		inicializar(x, y, w, NULL);
	}

	Inimigo_B::Inimigo_B(float x, float y, sf::RenderWindow* w, Jogador* _jogador) {
		inicializar(x, y, w, _jogador);
	}

	void Inimigo_B::inicializar(float x, float y, sf::RenderWindow* w, Jogador* _jogador) {
		body.setFillColor(sf::Color::Red);
		body.setPosition(x, y);
		this->window = w;
		this->jogador = _jogador;
		atirador = false;
		empuxo = true;
	}
}
