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
        Gerenciador_Colisoes* gc;
        int pontos;

    public:
        Jogador();
        ~Jogador();
        void setGC(Gerenciador_Colisoes* GC) { this->gc = GC; }
        void mover();
        void reduzirVida();
        void reviver();
        int getPontos() { return pontos; }
        void setPontos(int _pontos) { pontos = _pontos; }
        void aumentarPontos() { pontos++; }
        //void pular();
    };
}

