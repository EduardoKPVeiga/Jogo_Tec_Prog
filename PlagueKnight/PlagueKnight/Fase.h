#pragma once

#include <vector>
#include "Ente.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Inimigo_A.h"
#include "Inimigo_B.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Plataforma.h"

using namespace Jogadores;
using namespace Inimigos;

namespace Fases {
	class Fase : Ente {
	protected:
		Gerenciador_Colisoes cm;
		ListaEntidades* listaEntidades;
		Lista<Inimigo> ListEnemies;
		Plataforma plataforma;
		Jogador* jogador1;
		sf::RenderWindow* window;

	public:
		Fase();
		Fase(Jogador* jogador1, sf::RenderWindow* window);
		~Fase();
		ListaEntidades* getEntityList() { return listaEntidades; }
		void displayFase();
		virtual void inicializeElementos();
		void reposicaoPlataforma();
	};
}