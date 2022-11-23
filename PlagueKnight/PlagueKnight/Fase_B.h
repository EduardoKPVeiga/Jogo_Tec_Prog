#pragma once
#include "Fase.h"

namespace Fases {
    class Fase_B : public Fase {
	public:
		Fase_B();
		Fase_B(Jogador* jogador1, sf::RenderWindow* window);
		~Fase_B();
		void displayFase();
		void inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window);
		void desenhaPlataforma();
		void inicializaPlataforma();
		void inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window);
		void inicializaProjeteis();
    };
}

