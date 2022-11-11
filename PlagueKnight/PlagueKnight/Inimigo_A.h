#pragma once
#include "Inimigo.h"

namespace Inimigos {
	class Inimigo_A : public Inimigo {
	public:
		Inimigo_A();
		~Inimigo_A();
		Inimigo_A(float x, float y, sf::RenderWindow* w);
	};
}

