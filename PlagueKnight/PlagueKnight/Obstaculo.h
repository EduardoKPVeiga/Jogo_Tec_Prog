#pragma once
#include "Entidade.h"

namespace Obstaculos {
    class Obstaculo : public Entidade {
    protected:
       bool empuxo = true;
    
    public:
        Obstaculo();
        ~Obstaculo();
    
    };
}

