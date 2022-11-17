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
        ~Jogador();
        void mover();
        void pular();
    };
}

