#pragma once

#include "Inimigo.h"
#include "Projetil.h"

using namespace Personagens;

namespace Inimigos {
	class Inimigo_A : public Inimigo {
	private:
		//Projetil bolinha;
		//int direcaoDisparo;

	public:
		Inimigo_A();
		~Inimigo_A();
		Inimigo_A(float x, float y, sf::RenderWindow* w);
		//void atirar();
	};
}

