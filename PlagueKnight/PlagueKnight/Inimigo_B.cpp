#include "Inimigo_B.h"

namespace Inimigos {
	Inimigo_B::Inimigo_B() {
		body.setFillColor(sf::Color::Red);
	}

	Inimigo_B::~Inimigo_B() {}

	Inimigo_B::Inimigo_B(float x, float y, sf::RenderWindow* w) {
		body.setFillColor(sf::Color::Red);
		body.setPosition(x, y);
		this->window = w;
	}

	Inimigo_B::Inimigo_B(float x, float y, sf::RenderWindow* w, Jogador* _jogador) {
		body.setFillColor(sf::Color::Red);
		body.setPosition(x, y);
		this->window = w;
		this->jogador = _jogador;
	}
}
