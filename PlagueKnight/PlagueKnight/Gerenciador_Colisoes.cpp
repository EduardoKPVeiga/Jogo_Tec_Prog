#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"
using namespace std;

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
    body.setFillColor(sf::Color::Green);
    body.setPosition(100, 100);
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
}

void Gerenciador_Colisoes::setLO(Plataforma *obstaculo)
{
    LO.push(obstaculo);
}

void Gerenciador_Colisoes::verify_collisions(Personagem* personagem, int direction)
{
    if (LO.getLength() > 0)
    {
        for (int i = 0; i < LO.getLength(); i++)
        {
            
        }
    }
    else
        cout << "LISTA VAZIA" << endl;
}
