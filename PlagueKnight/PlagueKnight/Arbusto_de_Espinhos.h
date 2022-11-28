#pragma once

#include "Obstaculo.h"

namespace Obstaculos {
    class Arbusto_de_Espinhos : public Obstaculo {
    private:
        Jogador* jogador1;

    public:
        Arbusto_de_Espinhos();
        Arbusto_de_Espinhos(float _posX, float _posY, sf::RenderWindow* _window, Jogador* _jogador1);
        ~Arbusto_de_Espinhos();
        void inicializar(float _posX, float _posY, sf::RenderWindow* _window, Jogador* _jogador1);
        void danar();
    };
}

