#pragma once
#include "Obstaculo.h"
#include "Lista.h"
#include <SFML/Graphics.hpp>

using namespace Obstaculos;

class Plataforma : public Obstaculo {
public:
    Plataforma();
    ~Plataforma();
    Lista<Plataforma> getLista() { return LO; }
private:
    Lista<Plataforma> LO;
    
};

