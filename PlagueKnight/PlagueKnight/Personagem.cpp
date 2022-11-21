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

	void Personagem::atirar(Projetil* bolinha) {
		/*
			Arrumar funcao para criar a bolinha aqui;
			Personagem nao pode 'ter' bolinha;
			colocar bolinha na lista de entidades;
			tirar moverProjetil() de atirar.
		*/

		if (!(bolinha->getProjetilAtivo())) { // Se a bolinha nao foi atirada
			bolinha->setProjetilAtivo(true);
		}
	}

	int Personagem::getDirecaoDisparo() {
		return direcaoDisparo;
	}
}