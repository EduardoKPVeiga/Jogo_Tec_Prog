#include "Fase.h"

namespace Fases {
	Fase::Fase() {
		gc = new Gerenciador_Colisoes();
	}

	Fase::~Fase() {}

	void Fase::displayFase() {
		sf::Font font;
		if (!font.loadFromFile("resources/arial.ttf"))
		{
			exit(1);
		}
		sf::Texture texture;
		sf::Text text;

		//plataforma.setWindow(window);

		// Display
		window->clear(sf::Color::Black);

		if (jogador1->getVivo())
			jogador1->mover();
		else {
			jogador1->setBodyPosition(50.f, window->getSize().y - 100.f);
			jogador1->setVivo(true);
		}

		// Movendo inimigos
		for (int i = 0; i < listaInimigos.getLength(); i++) {
			listaInimigos.getItem(i)->mover(0.f, 0.f, 0.f);
		}

		// Inimigos atirando
		if (listaProjeteis.getLength() == listaAtiradores.getLength() && listaProjeteis.getLength() <= qtdInimigos) {
			for (int j = 0; j < listaAtiradores.getLength(); j++) {

				// Movendo projeteis
				listaProjeteis.getItem(j)->mover(listaAtiradores.getItem(j)->getPosX(), listaAtiradores.getItem(j)->getPosY(), listaAtiradores.getItem(j)->getDirecaoDisparo(), 2.5f);

				// Se esta perto do jogador atira
				if (listaAtiradores.getItem(j)->getVivo() && abs(listaAtiradores.getItem(j)->getPosX() - jogador1->getPosX()) <= 160.f && abs(jogador1->getPosY() - listaAtiradores.getItem(j)->getPosY()) <= 50.f) {
					listaAtiradores.getItem(j)->atirar();
				}

				else {
					listaProjeteis.getItem(j)->setProjetilAtivo(false);
				}
				
				//*
				// Se o projetil esta ativo e se colidiu
				if (listaProjeteis.getItem(j)->getProjetilAtivo() && gc->colidiuProjetilInimigo(listaProjeteis.getItem(j)->getBody(), jogador1->getBody(), listaProjeteis.getItem(j)->getDirecaoDisparo(), 5.f)) {
					jogador1->reduzirVida();
					listaProjeteis.getItem(j)->setBodyPosition(listaAtiradores.getItem(j)->getPosX(), listaAtiradores.getItem(j)->getPosY());
					listaProjeteis.getItem(j)->setProjetilAtivo(false);
				}
				//*/

				// Movendo projeteis
				listaProjeteis.getItem(j)->mover(listaAtiradores.getItem(j)->getPosX(), listaAtiradores.getItem(j)->getPosY(), listaAtiradores.getItem(j)->getDirecaoDisparo(), 2.5f);		
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			jogador1->atirar();

		bolinha->mover(jogador1->getPosX() + (jogador1->getBodySize() / 2), jogador1->getPosY() + (jogador1->getBodySize() / 2), jogador1->getDirecaoDisparo(), 5.f);
		if (bolinha->getProjetilAtivo() && gc->colidiuProjetilJogador(bolinha->getBody(), bolinha->getDirecaoDisparo(), 5.f)) {
			bolinha->setProjetilAtivo(false);
		}

		// Desenhando as entidades
		for (int i = 0; i < listaEntidades.getLength(); i++) {
			if (listaEntidades.getItem(i)->getVivo())
				listaEntidades.getItem(i)->draw();
		}

		// desenhando jogador
		if (jogador1->getVivo())
			jogador1->draw();

		// Desenhando projeteis
		for (int i = 0; i < listaProjeteis.getLength(); i++) {
			listaProjeteis.getItem(i)->draw();
		}

		bolinha->draw();

		// Desativa a fase se a vida do jogador chegar a 0
		if (!jogador1->getVidas()) {
			faseAtiva = false;
		}

		qtdInimigos = 0;
		for (int i = 0; i < listaInimigos.getLength(); i++) {
			if (listaInimigos.getItem(i)->getVivo())
				qtdInimigos++;
		}

		if (qtdInimigos == 0)
			faseAtiva = false;

		// Show player's life
		text.setFont(font);
		text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(qtdInimigos));
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
		window->draw(text);
	}

	bool Fase::getFaseAtiva() {
		return faseAtiva;
	}
}