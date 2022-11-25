#include "Arbusto_de_Espinhos.h"

namespace Obstaculos {
	Arbusto_de_Espinhos::Arbusto_de_Espinhos() {}

	Arbusto_de_Espinhos::Arbusto_de_Espinhos(float _posX, float _posY, sf::RenderWindow* _window) {
		inicializar(_posX, _posY, _window);
	}

	Arbusto_de_Espinhos::~Arbusto_de_Espinhos() {
		inicializar(0.f, 0.f, NULL);
	}

	void Arbusto_de_Espinhos::inicializar(float _posX, float _posY, sf::RenderWindow* _window) {
		body.setPosition(_posX, _posY);
		body.setFillColor(sf::Color::Green);
		this->window = _window;
		danoso = true;
		atirador = false;
		empuxo = true;
	}
}

