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
        ~Inimigo();
        void mover();
        void setFlyingSpeed(float s);
    };
}
