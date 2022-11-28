#pragma once

#include "Entidade.h"
#include "Jogador.h"

using namespace Jogadores;

namespace Obstaculos {
    class Obstaculo : public Entidade {
    protected:
       bool empuxo = true;
    
    public:
        Obstaculo();
        ~Obstaculo();
        virtual void danar() {}
    
    };
}

