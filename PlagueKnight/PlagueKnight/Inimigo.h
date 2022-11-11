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
        Inimigo(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, int num_v = 1, bool pulando = 0, float fSpeed = 0 /*, sf::RenderWindow* window*/);
        ~Inimigo();
        void move();
        void setFlyingSpeed(float s);
    };
}
