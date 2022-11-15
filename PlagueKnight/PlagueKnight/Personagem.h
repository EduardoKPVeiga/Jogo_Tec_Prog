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
        float x, y;

    public:
        // Construtoras e destrutoras
        Personagem();
        Personagem(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, sf::RenderWindow* w, int num_v = 1);
        ~Personagem();

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
    };
}

