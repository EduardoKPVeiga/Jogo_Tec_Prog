#pragma once

#include "Obstaculo.h"

namespace Obstaculos {
    class Arbusto_de_Espinhos : public Obstaculo {
    public:
        Arbusto_de_Espinhos();
        Arbusto_de_Espinhos(float _posX, float _posY, sf::RenderWindow* _window);
        ~Arbusto_de_Espinhos();
        void inicializar(float _posX, float _posY, sf::RenderWindow* _window);
    };
}

