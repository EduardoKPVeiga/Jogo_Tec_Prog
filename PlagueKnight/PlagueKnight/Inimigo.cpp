#include "Inimigo.h"

namespace Inimigos {
    Inimigo::Inimigo() {
        //body.setFillColor(sf::Color::Red);
        inicializar(0.f, 0.f, NULL, NULL);
    }

    Inimigo::Inimigo(float x, float y, sf::RenderWindow* w) {
        inicializar(x, y, w, NULL);
    }

    Inimigo::Inimigo(float x, float y, sf::RenderWindow* w, Jogador* _jogador) {
        inicializar(x, y, w, _jogador);
    }

    Inimigo::~Inimigo() {}

    void Inimigo::inicializar(float x, float y, sf::RenderWindow* w, Jogador* _jogador) {
        body.setFillColor(sf::Color::Red);
        body.setPosition(x, y);
        this->window = w;
        jogador = _jogador;
    }

    void Inimigo::mover(float _posX, float _posY, int _direcao)
    {
        sf::Vector2u size = window->getSize();
        sf::Vector2f enemyPosition = body.getPosition();
        sf::Vector2f enemySize = body.getSize();

        if (!empuxo) {
            receberGravidade(empuxo);
        }

        if (jogador->getPosX() < body.getPosition().x) {
            body.move(sf::Vector2f(-(velocidade / 4), 0));
            direcao = 0;
            direcaoDisparo = -1;
        }

        else if (jogador->getPosX() > body.getPosition().x) {
            body.move(sf::Vector2f((velocidade / 4), 0));
            direcao = 1;
            direcaoDisparo = 1;
        }
    }

    void Inimigo::setFlyingSpeed(float s)
    {
        this->flyingSpeed = s;
    }

    void Inimigo::atirar() {}
}