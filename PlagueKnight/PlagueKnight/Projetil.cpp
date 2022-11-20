#include "Projetil.h"

Projetil::Projetil() {
	body.setFillColor(sf::Color::Magenta);
	body.setSize(sf::Vector2f(5.f, 5.f));
	//time(&tempoAnte);
	//time(&tempoAtual);
}

Projetil::~Projetil() {}

void Projetil::setDano(int _dano) {
	dano = _dano;
}

int Projetil::getDano() {
	return dano;
}

void Projetil::setProjetilAtivo(bool _projetilAtivo) {
	projetilAtivo = _projetilAtivo;
}

bool Projetil::getProjetilAtivo() {
	return projetilAtivo;
}

void Projetil::moverProjetil(float _posX, float _posY, int _direcaoDisparo) {
	if (_posX <= window->getSize().x && _posX >= 0.f) {
		if (_posY <= window->getSize().y && _posY >= 0.f) {
			//time(&tempoAtual);

			if (!projetilAtivo) { // Se o projetil nao foi lancado, nao ha 'tempo de voo'
				//tempoAnte = tempoAtual;
				cout << "Projetil Desativo." << endl;
				posX = _posX;
				posY = _posY;
				projetilAtivo = true;
				body.setPosition(posX, posY);
			}

			//posY = posY + ((gravidade * powf(float(tempoAtual - tempoAnte), 2)) / 2); // delta_y = (g * (t ^ 2))/2
			//receberGravidade(false);

			if (projetilAtivo) {
				cout << "Projetil Ativo.";
				if ((_direcaoDisparo == 1 && posX <= (window->getSize().x + 10.f)) || (_direcaoDisparo == -1 && posX >= 10.f)) {
					//body.setPosition(posX + (10.f * _direcaoDisparo), posY);
					//tempoAnte = tempoAtual;

					posX += (10.f * _direcaoDisparo);
					body.move(posX, gravidade);
				}
			}

		}
		else {
			cout << "ERRO! Posicao Y invalida." << endl;
			return;
		}
	}
	else {
		cout << "ERRO! Posicao X invalida." << endl;
		return;
	}
}