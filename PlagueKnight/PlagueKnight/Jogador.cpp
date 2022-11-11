#include "Jogador.h"

namespace Jogadores {
    Jogador::Jogador() {
        body.setFillColor(sf::Color::Blue);
    }

    Jogador::Jogador(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, int num_v) :
        Personagem(x_inicial, y_inicial, caminho_textura, largura, comprimento, num_v) {
        body.setFillColor(sf::Color::Blue);
    }

    Jogador::~Jogador() {}

    void Jogador::mover() {
        sf::Vector2u tamanho = window->getSize();
        sf::Vector2f posJogador = body.getPosition();
        sf::Vector2f tamanhoJogador = body.getSize();

        cout << "T: " << tamanhoJogador.y << endl;
        cout << "P: " << posJogador.y << endl;
        cout << "C: " << collidedY << endl;

        if (posJogador.y + 30 < collidedY)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && posJogador.x < (tamanho.x - tamanhoJogador.x)) {
                body.move(sf::Vector2f(velocidade, 0.f));
                direcao = 1;
            }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && posJogador.x > 0) {
            body.move(sf::Vector2f(-velocidade, 0.f));
            direcao = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && posJogador.y > 0) {
            if (!estah_pulando)
                body.move(sf::Vector2f(0, vel_pulo));
        }

        if (posJogador.y < (tamanho.y - tamanhoJogador.y) && (body.getPosition().y < collidedY - tamanhoJogador.y)) {
            body.move(sf::Vector2f(0.0f, vel_queda));
            if (posJogador.y <= alturaMaxPulo)
                estah_pulando = true;

        }
        else
        {
            collidedY = (float)window->getSize().y;
            estah_pulando = false;
            alturaMaxPulo = posJogador.y - (tamanhoJogador.y * 6);
        }
    }
}
