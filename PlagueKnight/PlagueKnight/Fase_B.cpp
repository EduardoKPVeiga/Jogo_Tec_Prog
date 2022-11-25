#include "Fase_B.h"

namespace Fases {
	Fase_B::Fase_B() {
		inicializeElementos(NULL, NULL);
	}

	Fase_B::Fase_B(Jogador* _jogador1, sf::RenderWindow* _window) {
		inicializeElementos(_jogador1, _window);
	}

	Fase_B::~Fase_B() {}

	void Fase_B::inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window) {
		this->window = _window;
		this->jogador1 = _jogador1;

		//gc = new Gerenciador_Colisoes(&(listaEntidades->LOs), &(listaEntidades->LIs), &(listaEntidades->LPs));
		gc->setListaEntidades(&listaEntidades);

		//listaEntidades->LJs.push(jogador1);
		inicializaPlataforma();
		inicializaInimigos(_jogador1, _window);
		inicializaProjeteis();
		inicializaArbustos();

		jogador1->setProjetil(bolinha);

		jogador1->setGC(gc);
	}

	void Fase_B::inicializaPlataforma() {
		/*
		Plataforma* plataforma = new Plataforma();
		plataforma->getBody().setSize(sf::Vector2f(window->getSize().x, 25.f));
		plataforma->setBodyPosition(0.f, window->getSize().y - 25);
		listaEntidades.push(plataforma);
		//*/

		// Plataforma 1º nivel
		//*
		for (int i = 0; i < 44; i++)
		{
			Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 25, window);
			listaEntidades.push(plataforma);
		}
		//*/
	}

	void Fase_B::inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window) {

		unsigned seed = time(0);
		srand(seed);
		qtdInimigos = 0;
		qtdInimigosAtiradores = 0;

		for (int i = 0; i < (3 + (rand() % 3)); i++) {
			Inimigo_A* inimigoA;

			inimigoA = new Inimigo_A(0.f + 60 * i, window->getSize().y - 50, window, jogador1);
			inimigoA->setLimiteX(0.f, window->getSize().x);
			listaEntidades.push(inimigoA);
			listaInimigos.push(inimigoA);

			qtdInimigos++;
		}

		for (int i = 0; i < (3 + (rand() % 3)); i++) {
			Inimigo_C* inimigoC;

			inimigoC = new Inimigo_C(0.f + 100 * i, window->getSize().y - 50, window, jogador1);
			inimigoC->setLimiteX(0.f, window->getSize().x);
			listaEntidades.push(inimigoC);
			listaInimigos.push(inimigoC);

			qtdInimigos++;
		}

		/*
		Inimigo_B* inimigo1 = new Inimigo_B(0.f, window->getSize().y - 50, window, jogador1);
		Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
		Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
		Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);

		inimigo1->setAtirador(true);
		inimigo2->setAtirador(true);
		inimigo3->setAtirador(true);
		inimigo4->setAtirador(false);

		listaEntidades.push(inimigo1);
		listaEntidades.push(inimigo2);
		listaEntidades.push(inimigo3);
		listaEntidades.push(inimigo4);

		listaInimigos.push(inimigo1);
		listaInimigos.push(inimigo2);
		listaInimigos.push(inimigo3);
		listaInimigos.push(inimigo4);

		qtdInimigos = 4;
		//*/
	}

	void Fase_B::inicializaProjeteis() {
		bolinha = new Projetil(window);

		/*
		// Projeteis de inimigos B
		for (int i = 0; i < qtdInimigosAtiradores; i++) {
			Projetil* projetil = new Projetil(window);
			listaEntidades.push(projetil);
			listaProjeteis.push(projetil);
		}

		int j = 0;
		for (int i = 0; i < listaInimigos.getLength(); i++) {
			if (listaInimigos.getItem(i)->getAtirador()) {
				listaInimigos.getItem(i)->setProjetil(listaProjeteis.getItem(j));
				j++;
			}
		}
		//*/
	}

	void Fase_B::inicializaArbustos() {
		for (int i = 0; i < (3 + (rand() % 3)); i++) {
			Arbusto* arbusto = new Arbusto(window->getSize().x - 90 * i, window->getSize().y - 50, window);

			listaEntidades.push(arbusto);
		}
	}
}