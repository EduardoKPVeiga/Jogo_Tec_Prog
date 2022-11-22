#pragma once
#include "Personagem.h"
#include "Jogador.h"

using namespace Personagens;
using namespace Jogadores;

namespace Inimigos {
    class Inimigo : public Personagem {
    protected:
        bool estah_pulando = false;
        float flyingSpeed = 0;
        Jogador* jogador;

    public:
        Inimigo();
        Inimigo(float x, float y, sf::RenderWindow* window);
        Inimigo(float x, float y, sf::RenderWindow* window, Jogador* _jogador);
        ~Inimigo();
        void mover();
        void setFlyingSpeed(float s);
    };
}
