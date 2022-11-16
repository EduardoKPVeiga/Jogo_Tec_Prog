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
        Inimigo(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, sf::RenderWindow* window, int num_v = 1, bool pulando = 0, float fSpeed = 0);
        ~Inimigo();
        void move();
        void setFlyingSpeed(float s);
        void setJogador(Jogador* _pJogador);
        Jogador* getJogador();
    };
}
