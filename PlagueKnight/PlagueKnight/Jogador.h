    #pragma once

#include "Personagem.h"
#include <SFML/Window/Event.hpp>
#include <iostream>

using namespace std;
using namespace Personagens;

namespace Jogadores {
    class Jogador : public Personagem {
    private:
        bool estah_pulando = false;

    public:
        Jogador();
        Jogador(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, int num_v = 1, sf::RenderWindow* w = NULL);
        ~Jogador();
        void mover();
        void pular();
    };
}

