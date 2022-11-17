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
        Jogador* pJogador;

    public:
        Inimigo();
        Inimigo(float x, float y, sf::RenderWindow* window);
        ~Inimigo();
        void move();
        void setFlyingSpeed(float s);
        void setJogador(Jogador* _pJogador);
        Jogador* getJogador();
    };
}
