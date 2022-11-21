#pragma once

#include "Entidade.h"
#include "Projetil.h"

namespace Personagens {
    class Personagem : public Entidade {
    protected:
        float velocidade = 5.000022f;
        float vel_pulo = -gravidade * 2.0f;
        int num_vidas;
        int direcao = 1;
        float alturaMaxPulo;
        bool empuxo = false;
        int direcaoDisparo;

    public:
        Personagem();
        ~Personagem();
        int getVidas();
        int getDirection() { return direcao; }
        void setVelocidade(float v);
        void setFlyingSpeed(float s);
        void atirar(Projetil* bolinha);
        int getDirecaoDisparo() { return direcaoDisparo; }
    };
}

