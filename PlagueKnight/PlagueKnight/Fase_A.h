#pragma once
#include "Fase.h"

namespace Fases {
	class Fase_A :public Fase {
	public:
		Fase_A();
		Fase_A(Jogador* jogador1, sf::RenderWindow* window);
		~Fase_A();
		void displayFase();
		void inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window);
		void inicializaPlataforma();
		void inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window);
		void inicializaProjeteis();
	};
}

