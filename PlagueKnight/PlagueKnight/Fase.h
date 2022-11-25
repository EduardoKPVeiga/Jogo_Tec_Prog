#pragma once

#include "Ente.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Inimigo_A.h"
#include "Inimigo_B.h"
#include "Inimigo_C.h"
#include "ListaEntidades.h"
#include "Plataforma.h"
#include "Resolucao.h"
#include "Projetil.h"
#include "Arbusto.h"
#include "Arbusto_de_Espinhos.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace Jogadores;
using namespace Inimigos;

namespace Fases {
	class Fase : Ente {
	protected:
		Lista<Entidade> listaEntidades;
		Gerenciador_Colisoes* gc;
		Lista<Projetil> listaProjeteis;
		Lista<Inimigo> listaInimigos;
		//ListaEntidades* listaEntidades;
		//Lista<Inimigo> ListEnemies;
		//Lista<Obstaculo> LO;
		//Lista<Projetil> listProjetil;
		//Plataforma plataforma;
		Jogador* jogador1;
		Projetil* bolinha;
		sf::RenderWindow* window;
		int qtdInimigos;
		int qtdInimigosAtiradores;

	public:
		Fase();
		~Fase();
		Lista<Entidade>* getEntityList() { return &listaEntidades; }
		//Lista<Obstaculo> getObstaculos() { return listaEntidades->LOs; }
		void setGC(Gerenciador_Colisoes* _gc) { this->gc = _gc; }
		int getQtdInimigos() { return qtdInimigos; }
		void setQtdInimigos(int _qtdInimigos) { qtdInimigos = _qtdInimigos; }
		void displayFase();
	};
}