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
        danoso = true;
        limiteEsqX = 0.f;
        limiteDirX = 0.f;
    }

    void Inimigo::mover(float _posX, float _posY, int _direcao)
    {
        sf::Vector2u size = window->getSize();
        sf::Vector2f enemyPosition = body.getPosition();
        sf::Vector2f enemySize = body.getSize();

        if (!empuxo) {
            receberGravidade(empuxo);
        }

        // Se o jogador esta a esquerda do inimigo
        if (jogador->getPosX() < body.getPosition().x) {

            // Se o jogador esta proximo do inimigo
            if ((body.getPosition().x - jogador->getPosX() <= 80.f) && (jogador->getPosY() - body.getPosition().y <= 50.f || body.getPosition().y - jogador->getPosY() <= 50.f)) {

                // Se esta nos limites da plataforma
                if (body.getPosition().x - (velocidade / 4) >= limiteEsqX) {
                    body.move(sf::Vector2f(-(velocidade / 4), 0));
                }
            }
            direcao = 0;
            direcaoDisparo = -1;
        }

        // Se o jogador esta a direita do inimigo
        else if (jogador->getPosX() > body.getPosition().x) {

            // Se o jogador esta proximo do inimigo
            if ((jogador->getPosX() - body.getPosition().x <= 80.f) && (jogador->getPosY() - body.getPosition().y <= 50.f || body.getPosition().y - jogador->getPosY() <= 50.f)) {

                // Se esta nos limites da plataforma
                if (body.getPosition().x + (velocidade / 4) <= limiteDirX) {
                    body.move(sf::Vector2f((velocidade / 4), 0));
                }
            }
            direcao = 1;
            direcaoDisparo = 1;
        }
    }

    void Inimigo::setFlyingSpeed(float s)
    {
        this->flyingSpeed = s;
    }

    void Inimigo::atirar() {}

    float Inimigo::getLimiteEsqX() {
        return limiteEsqX;
    }

    float Inimigo::getLimiteDirX() {
        return limiteDirX;
    }

    void Inimigo::setLimiteX(float _limiteEsqX, float _limiteDirX) {
        limiteEsqX = _limiteEsqX;
        limiteDirX = _limiteDirX;
    }
}