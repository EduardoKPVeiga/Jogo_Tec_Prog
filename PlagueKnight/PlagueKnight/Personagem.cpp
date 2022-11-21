#include "Personagem.h"

namespace Personagens {
    Personagem::Personagem() {}

    Personagem::~Personagem() {}

    int Personagem::getVidas() {
        return num_vidas;
    }

    void Personagem::setVelocidade(float v) {
        this->velocidade = v;
    }

	void Personagem::atirar(Projetil* bolinha) {
		if (!(bolinha->getProjetilAtivo())) { // Se a bolinha nao foi atirada
			bolinha->setProjetilAtivo(true);
		}
	}
}