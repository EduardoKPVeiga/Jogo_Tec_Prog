#pragma once
#include "Inimigo.h"

// Atirador

namespace Inimigos {
	class Inimigo_B :public Inimigo {

	public:
		Inimigo_B();
		~Inimigo_B();
		Inimigo_B(float x, float y, sf::RenderWindow* w);
		Inimigo_B(float x, float y, sf::RenderWindow* w, Jogador* _jogador);
		void inicializar(float x, float y, sf::RenderWindow* w, Jogador* _jogador);
		void atirar();
	};
}
