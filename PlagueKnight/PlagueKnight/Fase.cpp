#include "Fase.h"

namespace Fases {
    Fase::Fase() {
        gc = new Gerenciador_Colisoes();
    }

    Fase::~Fase() {}
}