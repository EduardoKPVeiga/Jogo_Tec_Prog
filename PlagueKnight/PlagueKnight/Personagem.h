#pragma once

#include "Entidade.h"
#include <SFML/Graphics.hpp>

namespace Personagens {
    class Personagem : public Entidade {
    protected:
        float velocidade = 5.000022f;
        float vel_queda = 20.000055f;
        float vel_pulo = -vel_queda * 2.0f;
        int num_vidas;
        int direcao = 1;
        float alturaMaxPulo;
        float collidedY;
        float collidedX;
        float x;
        float y;

    public:
        Personagem();
        Personagem(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, int num_v = 1);
        ~Personagem();

        void setNumVidas(int num_v);
        int getVidas();

        void setAlturaMaxPulo(float h);
        float getAlturaMaxPulo();

        void setVelocidade(float v);
        void setFlyingSpeed(float s);

        void setCollidedX(float value) { this->collidedX = value; }
        void setCollidedY(float value) { this->collidedY = value; }
    };
}

