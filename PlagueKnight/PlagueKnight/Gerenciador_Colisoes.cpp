#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"
using namespace std;

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
    body.setFillColor(sf::Color::Green);
    body.setPosition(100, 100);
}

Gerenciador_Colisoes::Gerenciador_Colisoes(Lista<Obstaculo> LOs, Lista<Inimigo>ListEnemies)
{
    LOs = LOs;
    ListEnemies = ListEnemies;
}
Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
}

void Gerenciador_Colisoes::setLO(Plataforma *obstaculo)
{
    LOs.push(obstaculo);
}

bool Gerenciador_Colisoes::colidiuJogador(sf::RectangleShape body, int direction)
{
    sf::RectangleShape body_futuro;
    body_futuro = body;
    if (LOs.getLength() > 0)
    {
        for (int i = 0; i < LOs.getLength(); i++)
        {
            if (direction == 4)
            {
                body_futuro.move(0.f, 1);
                if (body_futuro.getGlobalBounds().intersects(LOs.getItem(i)->getBodyGlobalBounds()))
                {
                    return true;
                }
            }
            if (direction == 3)
            {

            }
            
        }
    }
    else
        cout << "LISTA VAZIA" << endl;
        return false;
}
