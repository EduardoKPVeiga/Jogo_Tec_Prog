#include "Gerenciador_Colisoes.h"

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

void Gerenciador_Colisoes::verify_collisions(Personagem* person)
{
    if (LO.getLength() > 0)
    {
        for (int i = 0; i < LO.getLength(); i++)
        {
            if (LO.getItem(i)->getBody().getGlobalBounds().intersects(person->getBody().getGlobalBounds()))
            {
                person->setCollidedX(LO.getItem(i)->getBody().getPosition().x);
                person->setCollidedY(LO.getItem(i)->getBody().getPosition().y);
            }
        }
    }
    else
        cout << "LISTA VAZIA" << endl;
}
