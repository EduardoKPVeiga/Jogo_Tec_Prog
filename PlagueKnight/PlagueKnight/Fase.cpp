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

		//listaEntidades->moveEntities(jogador1->getPosX(), jogador1->getPosY(), jogador1->getDirecaoDisparo());

		// Inimigos atirando
		int j = 0;
		for (int i = 0; i < listaInimigos.getLength(); i++) {

			// Movendo inimigos
			listaInimigos.getItem(i)->mover(0.f, 0.f, 0.f);

			// Inimigos atirando
			if (listaProjeteis.getLength() != 0) {
				if (listaInimigos.getItem(i)->getAtirador()) {
					if (listaProjeteis.getLength() <= qtdInimigos) {
						listaInimigos.getItem(i)->atirar();
					}

					else {
						cout << "ERRO: quantidade de projeteis insuficiente!" << endl;
					}

					// Movendo projeteis
					listaProjeteis.getItem(j)->mover(listaInimigos.getItem(i)->getPosX(), listaInimigos.getItem(i)->getPosY(), listaInimigos.getItem(i)->getDirecaoDisparo());
					j++;
				}
			}
		}

		// Desenhando as entidades
		for (int i = 0; i < listaEntidades.getLength(); i++) {
			if(listaEntidades.getItem(i)->getVivo())
				listaEntidades.getItem(i)->draw();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			jogador1->atirar();

		bolinha->mover(jogador1->getPosX() + (jogador1->getBodySize() / 2), jogador1->getPosY() + (jogador1->getBodySize() / 2), jogador1->getDirecaoDisparo());

		if(jogador1->getVivo())
			jogador1->draw();
		bolinha->draw();

		//listaEntidades->drawEntities(window);

		//this->desenhaPlataforma();

		// Show player's life
		text.setFont(font);
		text.setString("Vidas: " + std::to_string(jogador1->getVidas()) + " Enemies: " + std::to_string(qtdInimigos));
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
		window->draw(text);
	}
}