#pragma once

#include "Inimigo.h"

// Boss

namespace Inimigos {
	class Inimigo_C : public Inimigo {
	public:
		Inimigo_C();
		~Inimigo_C();
		Inimigo_C(float x, float y, sf::RenderWindow* w);
		Inimigo_C(float x, float y, sf::RenderWindow* w, Jogador* _jogador);
		void inicializar(float x, float y, sf::RenderWindow* w, Jogador* _jogador);
	};
}

