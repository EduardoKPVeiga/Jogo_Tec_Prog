#pragma once

#include "Obstaculo.h"

namespace Obstaculos {
	class Arbusto : public Obstaculo {
	public:
		Arbusto();
		Arbusto(float _posX, float _posY, sf::RenderWindow* _window);
		~Arbusto();
		void inicializar(float _posX, float _posY, sf::RenderWindow* _window);
	};
}

