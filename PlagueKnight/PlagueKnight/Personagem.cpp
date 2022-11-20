#include "Personagem.h"

namespace Personagens {
	Personagem::Personagem() {
		inicializa_personagem();
	}

	Personagem::~Personagem() {}

	void Personagem::inicializa_personagem() {
		num_vidas = 0;
		alturaMaxPulo = 0;
		collidedX = 0;
		collidedY = 0;
	}

	void Personagem::setNumVidas(int num_v) {
		num_vidas = num_v;
	}

	int Personagem::getVidas() {
		return num_vidas;
	}

	void Personagem::setAlturaMaxPulo(float h) {
		alturaMaxPulo = h;
	}

	float Personagem::getAlturaMaxPulo() {
		return alturaMaxPulo;
	}

	void Personagem::setVelocidade(float v) {
		this->velocidade = v;
	}

	void Personagem::atirar() {
		if (!(bolinha->getProjetilAtivo())) { // Se a bolinha nao foi atirada
			if (direcao == 0)
				direcaoDisparo = -1;
			else if (direcao == 1)
				direcaoDisparo = 1;

			bolinha->setProjetilAtivo(true);
		}
		bolinha->moverProjetil(posX, posY, direcaoDisparo);
		bolinha->draw();
	}
}