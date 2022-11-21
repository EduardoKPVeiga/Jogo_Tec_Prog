#pragma once

#include "Ente.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Inimigo_A.h"
#include "Inimigo_B.h"
#include "ListaEntidades.h"
#include "Plataforma.h"
#include "Resolucao.h"
#include "Projetil.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace Jogadores;
using namespace Inimigos;

namespace Fases {
	class Fase : Ente {
	private:
		Gerenciador_Colisoes* gc;
		ListaEntidades* listaEntidades;
		Lista<Inimigo> ListEnemies;
		Lista<Obstaculo> LO;
		//Plataforma plataforma;
		Jogador* jogador1;
		Projetil* bolinha;
		sf::RenderWindow* window;

	public:
		Fase();
		Fase(Jogador* jogador1, sf::RenderWindow* window);
		~Fase();
		ListaEntidades* getEntityList() { return listaEntidades; }
		void displayFase();
		void inicializeElementos();
		void desenhaPlataforma();
		void inicializaPlataforma();
		Lista<Obstaculo> getObstaculos() { return LO; }
	};
}