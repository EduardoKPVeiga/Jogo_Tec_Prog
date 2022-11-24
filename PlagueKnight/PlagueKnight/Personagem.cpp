#include "Personagem.h"

namespace Personagens {
    Personagem::Personagem() {
        inicializar();
    }

    Personagem::~Personagem() {}

    void Personagem::inicializar() {
        num_vidas = 0;
        alturaMaxPulo = 0;
        direcaoDisparo = 0;
    }

    int Personagem::getVidas() {
        return num_vidas;
    }

    void Personagem::setNumVidas(int _num_vidas) {
        num_vidas = _num_vidas;
    }

    void Personagem::setVelocidade(float v) {
        this->velocidade = v;
    }

	void Personagem::atirar() {
		if (!(projetil->getProjetilAtivo())) { // Se a bolinha nao foi atirada
            projetil->setProjetilAtivo(true);
		}
	}
}