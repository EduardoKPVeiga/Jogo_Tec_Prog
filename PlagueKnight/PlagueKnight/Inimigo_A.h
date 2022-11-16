#pragma once
#include "Inimigo.h"

using namespace Personagens;

namespace Inimigos {
	class Inimigo_A : public Inimigo {
	private:
		sf::RectangleShape flecha;
		sf::FloatRect flecha_colisao;

	public:
		Inimigo_A();
		~Inimigo_A();
		Inimigo_A(float x, float y, sf::RenderWindow* w);
		void atirar();
	};
}

