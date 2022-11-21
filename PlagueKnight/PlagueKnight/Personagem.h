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
        float collidedY;
        float collidedX;
        bool empuxo = false;
        int direcaoDisparo;

    public:
        // Construtoras e destrutoras
        Personagem();
        ~Personagem();

        void setWindow(sf::RenderWindow* window) { this->window = window;/* bolinha->setWindow(window);*/ }

        // Inicializadora
        void inicializa_personagem();

        // Vidas
        void setNumVidas(int num_v);
        int getVidas();

        // Altura de pulo
        void setAlturaMaxPulo(float h);
        float getAlturaMaxPulo();

        // Velocidades
        void setVelocidade(float v);
        void setFlyingSpeed(float s);

        // Colisoes
        void setCollidedX(float value) { this->collidedX = value; }
        void setCollidedY(float value) { this->collidedY = value; }

        void atirar(Projetil* bolinha);

        virtual void mover(float _posX, float _posY, int _direcao) {}

        int getDirecaoDisparo();
    };
}

