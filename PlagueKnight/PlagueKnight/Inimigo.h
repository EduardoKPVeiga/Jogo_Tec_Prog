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
        void inicializar(float x, float y, sf::RenderWindow* w, Jogador* _jogador);
        void mover(float _posX, float _posY, int _direcao);
        void setFlyingSpeed(float s);
        virtual void atirar();
    };
}
