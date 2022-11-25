#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"

using namespace std;

Gerenciador_Colisoes::Gerenciador_Colisoes() {
    inicializar(NULL);
    //body.setFillColor(sf::Color::Green);
    //body.setPosition(100, 100);
}

Gerenciador_Colisoes::Gerenciador_Colisoes(Lista<Entidade>* _listaEntidades) {
    inicializar(_listaEntidades);
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

void Gerenciador_Colisoes::inicializar(Lista<Entidade>* _listaEntidades) {
    listaEntidades = _listaEntidades;
    j1 = NULL;
}

bool Gerenciador_Colisoes::colidiuJogador(sf::RectangleShape _body, int direction) {
    sf::RectangleShape body_futuro;
    body_futuro = _body;

    if (direction == 4) {
        body_futuro.move(0.f, gravidade);
    }

    else if (direction == 3) {
        body_futuro.move(0.f, -gravidade);
    }

    else if (direction == 2) {
        body_futuro.move(5.000022f, 0.f);
    }

    if (direction == 1) {
        body_futuro.move(-5.000022f, 0.f);
    }

    if (listaEntidades->getLength() > 0) {
        //cout << "Tamanho listaEntidades: " << listaEntidades->getLength() << endl;

        for (int i = 0; i < listaEntidades->getLength(); i++) {

            /*
            if (body_futuro.getGlobalBounds().intersects(listaEntidades->getItem(i)->getBodyGlobalBounds())) { // ****

                // Se for danoso
                if (listaEntidades->getItem(i)->getDanoso()) {

                    // causar dano
                    listaEntidades->getItem(i)->danar();
                }
                return true;
            }
            //*/

            //*
            // Se a diferenca entre as distancias em x e em y sao menores que o tamanho do corpo
            if ( (abs(body_futuro.getPosition().x - listaEntidades->getItem(i)->getPosX()) <= body_futuro.getSize().x)
                && (abs(body_futuro.getPosition().y - listaEntidades->getItem(i)->getPosY()) <= body_futuro.getSize().y)) {
                return true;
            }

            /*
            // Se colidiu em x pela direita e se o modulo da diferenca entre as alturas eh menor que o tamanho do corpo
            if ( (listaEntidades->getItem(i)->getPosX() - body_futuro.getPosition().x <= body_futuro.getSize().x)
                && (body_futuro.getPosition().y - listaEntidades->getItem(i)->getPosY() <= body_futuro.getSize().y
                    && listaEntidades->getItem(i)->getPosY() - body_futuro.getPosition().y <= body_futuro.getSize().y) ) {
                cout << "2º if do GC." << endl;
                return true;
            }
            //*/
        }
    }

    else
        cout << "LISTA VAZIA" << endl;

    return false;
}

void Gerenciador_Colisoes::setListaEntidades(Lista<Entidade>* _listaEntidades) {
    this->listaEntidades = _listaEntidades;
    if (!listaEntidades)
        cout << "ERRO: lista de entidades NULL." << endl;
}

Lista<Entidade>* Gerenciador_Colisoes::getListaEntidades() {
    return listaEntidades;
}

/*
void Gerenciador_Colisoes::setLO(Plataforma *obstaculo)
{
    LOs->push(obstaculo);
}
//*/