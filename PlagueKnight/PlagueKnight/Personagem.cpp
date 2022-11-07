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
}