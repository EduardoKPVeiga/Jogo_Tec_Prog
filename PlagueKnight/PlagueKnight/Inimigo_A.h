#pragma once
#include "Inimigo.h"

// Comum

namespace Inimigos {
	class Inimigo_A : public Inimigo {
	public:
		Inimigo_A();
		~Inimigo_A();
		Inimigo_A(float x, float y, sf::RenderWindow* w);
		Inimigo_A(float x, float y, sf::RenderWindow* w, Jogador* _jogador);
		void inicializar(float x, float y, sf::RenderWindow* w, Jogador* _jogador);
	};
}

