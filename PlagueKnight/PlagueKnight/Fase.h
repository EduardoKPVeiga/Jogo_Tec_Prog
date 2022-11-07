#pragma once

#include <vector>
#include "Ente.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Inimigo_A.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Plataforma.h"

using namespace Jogadores;

namespace Fases {
	class Fase:Ente {
	private:
		Collisions_Manager cm;
		EntityList* entityList;
		List<Enemy> ListEnemies;
		Platform platform;
		Jogador* jogador1;
		sf::RenderWindow* window;

	public:
		Fase();
		Fase(Jogador* jogador1, sf::RenderWindow* window);
		~Fase();
		EntityList* getEntityList() { return entityList; }
		void displayFase();
		void inicializeElementos();
		void reposicaoPlataforma();
	};
}