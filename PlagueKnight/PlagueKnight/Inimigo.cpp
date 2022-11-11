#include "Inimigo.h"

namespace Inimigos {
    Inimigo::Inimigo()
    {
        body.setFillColor(sf::Color::Red);
        body.setPosition(0.f, 0.f); // ?
    }
    Inimigo::Inimigo(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, int num_v = 1, bool pulando = 0, float fSpeed = 0 /*, sf::RenderWindow* w*/) :
        Personagem(x_inicial, y_inicial, caminho_textura, largura, comprimento, num_v) {
        body.setFillColor(sf::Color::Red);
        estah_pulando = pulando;
        flyingSpeed = fSpeed;
        body.setPosition(x, y); // ?
        //this->window = w;
    }

    Inimigo::~Inimigo()
    {
    }

    void Inimigo::move()
    {
        sf::Vector2u size = window->getSize();
        sf::Vector2f enemyPosition = body.getPosition();
        sf::Vector2f enemySize = body.getSize();

        /*
        if (enemyPosition.x + enemySize.x == (float)window->getSize().x) {
            direction = 0;
        }
        */

        if (enemyPosition.y + 30 < collidedY)
            if (direcao == 1 && enemyPosition.x < (size.x - enemySize.x)) {
                body.move(sf::Vector2f(velocidade, 0.f));
                direcao = 1;
            }

        if (direcao == 0 && enemyPosition.x > 0) {
            body.move(sf::Vector2f(-velocidade, 0.f));
            direcao = 0;
        }

        if (enemyPosition.y < (size.y - enemySize.y) && (body.getPosition().y < collidedY - enemySize.y) && flyingSpeed != 20.000055f) {
            body.move(sf::Vector2f(0.0f, vel_queda));
            if (enemyPosition.y <= alturaMaxPulo)
                estah_pulando = true;

        }

        else
        {
            collidedY = (float)window->getSize().y;
            estah_pulando = false;
            alturaMaxPulo = enemyPosition.y - (enemySize.y * 6);
        }
    }

    void Inimigo::setFlyingSpeed(float s)
    {
        this->flyingSpeed = s;
    }
}