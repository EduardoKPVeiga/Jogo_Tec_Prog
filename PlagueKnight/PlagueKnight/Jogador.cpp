#include "Jogador.h"
#include "Gerenciador_Colisoes.h"

namespace Jogadores {
    Jogador::Jogador() {
        num_vidas = 3;
        body.setFillColor(sf::Color::Blue);
        gc = NULL;
        danoso = false;
        //gc = new Gerenciador_Colisoes();
    }

    Jogador::~Jogador() {}

    void Jogador::mover() {

        if (!gc)
            cout << "gc NULL!" << endl;

        sf::Vector2u tamanho = window->getSize();
        sf::Vector2f posJogador = body.getPosition();
        sf::Vector2f tamanhoJogador = body.getSize();

        bool colidiu;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && posJogador.x < (tamanho.x - tamanhoJogador.x)) {
            colidiu = gc->colidiuJogador(body, 1);
            //if (gc->colidiuJogador(body, 1) == false) {
            //cout << "Jogador colidiu em D: " << colidiu << endl;
            if (colidiu == false) {
                body.move(sf::Vector2f(velocidade, 0.f));
            }
             direcao = 1;
             direcaoDisparo = 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && posJogador.x > 0) {
            colidiu = gc->colidiuJogador(body, 2);
            //cout << "Jogador colidiu em A: " << colidiu << endl;
            //if (gc->colidiuJogador(body, 2) == false) {
            if (colidiu == false) {
                body.move(sf::Vector2f(-velocidade, 0.f));
            }
            direcao = 0;
            direcaoDisparo = -1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && posJogador.y > 0) {
            direcao = 3;
            if (!estah_pulando) {
                colidiu = gc->colidiuJogador(body, 3);
                //cout << "Jogador colidiu em W: " << colidiu << endl;
                //if (gc->colidiuJogador(body, 3) == false) {
                if (colidiu == false) {
                    body.move(sf::Vector2f(0, vel_pulo));
                }
            }
        }
        direcao = 4;
        colidiu = gc->colidiuJogador(body, 4);
        //cout << "Jogador colidiu em S: " << colidiu << endl;
        //if (gc->colidiuJogador(body, 4) == false) {
        if (colidiu == false) {
            receberGravidade(false);
            direcao = 4;

            if (posJogador.y <= alturaMaxPulo)
                estah_pulando = true;
        }
        
        else {
            estah_pulando = false;
            alturaMaxPulo = posJogador.y - (tamanhoJogador.y * 6);
            
        }
        
    }

    void Jogador::reduzirVida() {
        if (num_vidas >= 1)
            num_vidas--;

        if(num_vidas == 0)
            vivo = false;
    }
}
