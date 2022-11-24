#include "Arbusto.h"

namespace Obstaculos {
	Arbusto::Arbusto() {}

	Arbusto::Arbusto(float _posX, float _posY, sf::RenderWindow* _window) {
		inicializar(_posX, _posY, _window);
	}

	Arbusto::~Arbusto() {
		inicializar(0.f, 0.f, NULL);
	}

	void Arbusto::inicializar(float _posX, float _posY, sf::RenderWindow* _window) {
		body.setPosition(_posX, _posY);
		body.setFillColor(sf::Color::Green);
		this->window = _window;
		danoso = false;
		atirador = false;
		empuxo = true;
	}
}
