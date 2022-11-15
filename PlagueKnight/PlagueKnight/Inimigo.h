#pragma once
#include "Personagem.h"

using namespace Personagens;

namespace Inimigos {
    class Inimigo : public Personagem {
    protected:
        bool estah_pulando = false;
        float flyingSpeed = 0;

    public:
        Inimigo();
        Inimigo(float x, float y, sf::RenderWindow* window);
        Inimigo(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, sf::RenderWindow* window, int num_v = 1, bool pulando = 0, float fSpeed = 0);
        ~Inimigo();
        void move();
        void setFlyingSpeed(float s);
    };
}
