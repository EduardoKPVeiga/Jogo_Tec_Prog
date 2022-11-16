#include "Jogador.h"
#include "Gerenciador_Colisoes.h"

namespace Jogadores {
    Jogador::Jogador() {
        num_vidas = 3;
        body.setFillColor(sf::Color::Blue);

        gc = new Gerenciador_Colisoes();
    }

    Jogador::~Jogador() {}

    void Jogador::mover() {
        sf::Vector2u tamanho = window->getSize();
        sf::Vector2f posJogador = body.getPosition();
        sf::Vector2f tamanhoJogador = body.getSize();

        cout << "T: " << tamanhoJogador.y << endl;
        cout << "P: " << posJogador.y << endl;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && posJogador.x < (tamanho.x - tamanhoJogador.x)) {
             body.move(sf::Vector2f(velocidade, 0.f));
             direcao = 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && posJogador.x > 0) {
            body.move(sf::Vector2f(-velocidade, 0.f));
            direcao = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && posJogador.y > 0) {
            direcao = 3;
            if (!estah_pulando)
                body.move(sf::Vector2f(0, vel_pulo));
        }
        if (gc->colidiuJogador(body, 4)==false) {
            receberGravidade(false);
            direcao = 4;
            if (posJogador.y <= alturaMaxPulo)
                estah_pulando = true;

        }
        else
        {
            body.move(200, 200);
        }
        /*
        else
        {
            
            estah_pulando = false;
            alturaMaxPulo = posJogador.y - (tamanhoJogador.y * 6);
            
        }
        */
    }
}
