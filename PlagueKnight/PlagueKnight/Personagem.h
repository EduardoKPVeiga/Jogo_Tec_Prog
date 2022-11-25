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
        Projetil* projetil;

    public:
        Personagem();
        ~Personagem();
        void inicializar();
        int getVidas();
        void setNumVidas(int _num_vidas);
        int getDirection() { return direcao; }
        void setVelocidade(float v);
        virtual void setFlyingSpeed(float s) {}
        virtual void atirar();
        int getDirecaoDisparo() { return direcaoDisparo; }
        virtual void mover(float _posX, float _posY, int _direcao) {}
        void setProjetil(Projetil* _projetil) { projetil = _projetil; }
        virtual void danar();
    };
}

