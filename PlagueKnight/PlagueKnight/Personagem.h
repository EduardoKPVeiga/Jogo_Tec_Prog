#pragma once

#include "Entidade.h"

namespace Personagens {
    class Personagem : public Entidade {
    protected:
        float velocidade = 5.000022f;
        float vel_pulo = -gravidade * 2.0f;
        int num_vidas;
        int direcao = 1;
        float alturaMaxPulo;
        float collidedY;
        float collidedX;
        bool empuxo = false;

    public:
        Personagem();
        ~Personagem();
        int getVidas();
        void setVelocidade(float v);
        void setFlyingSpeed(float s);
        void setCollidedX(float value) { this->collidedX = value; }
        void setCollidedY(float value) { this->collidedY = value; }
    };
}

