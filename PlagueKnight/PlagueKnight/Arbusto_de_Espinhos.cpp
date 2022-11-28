#include "Arbusto_de_Espinhos.h"

namespace Obstaculos {
	Arbusto_de_Espinhos::Arbusto_de_Espinhos() {
		inicializar(0.f, 0.f, NULL, NULL);
	}

	Arbusto_de_Espinhos::Arbusto_de_Espinhos(float _posX, float _posY, sf::RenderWindow* _window, Jogador* _jogador1) {
		inicializar(_posX, _posY, _window, _jogador1);
	}

	Arbusto_de_Espinhos::~Arbusto_de_Espinhos() {}

	void Arbusto_de_Espinhos::inicializar(float _posX, float _posY, sf::RenderWindow* _window, Jogador* _jogador1) {
		body.setPosition(_posX, _posY);
		body.setFillColor(sf::Color::Green);
		this->window = _window;
		jogador1 = _jogador1;
		danoso = true;
		atirador = false;
		empuxo = true;
	}

	void Arbusto_de_Espinhos::danar() {
		jogador1->reduzirVida();
		jogador1->setBodyPosition(50.f, window->getSize().y - 100.f);
	}
}

