#include "Gerenciador_Colisoes.h"

using namespace std;

Gerenciador_Colisoes::Gerenciador_Colisoes() {
    inicializar(NULL, NULL);
    //body.setFillColor(sf::Color::Green);
    //body.setPosition(100, 100);
}

Gerenciador_Colisoes::Gerenciador_Colisoes(Lista<Entidade>* _listaEntidades) {
    inicializar(_listaEntidades, NULL);
}

Gerenciador_Colisoes::Gerenciador_Colisoes(Lista<Entidade>* _listaEntidades, Lista<Inimigo>* _listaInimigos) {
    inicializar(_listaEntidades, _listaInimigos);
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

void Gerenciador_Colisoes::inicializar(Lista<Entidade>* _listaEntidades, Lista<Inimigo>* _listaInimigos) {
    listaEntidades = _listaEntidades;
    listaInimigos = _listaInimigos;
}

bool Gerenciador_Colisoes::colidiuJogador(sf::RectangleShape _body, int direction, float _velX) {
    sf::RectangleShape body_futuro;
    body_futuro = _body;

    if (direction == 4) {
        body_futuro.move(0.f, gravidade);
    }

    else if (direction == 3) {
        body_futuro.move(0.f, -gravidade);
    }

    else if (direction == 2) {
        body_futuro.move(_velX, 0.f);
    }

    if (direction == 1) {
        body_futuro.move(-_velX, 0.f);
    }

    if (listaEntidades->getLength() > 0) {
        //cout << "Tamanho listaEntidades: " << listaEntidades->getLength() << endl;

        for (int i = 0; i < listaEntidades->getLength(); i++) {

            // Se a diferenca entre as distancias em x e em y sao menores que o tamanho do corpo
            if (listaEntidades->getItem(i)->getVivo()) {
                if ((abs(body_futuro.getPosition().x - listaEntidades->getItem(i)->getPosX()) <= body_futuro.getSize().x)
                    && (abs(body_futuro.getPosition().y - listaEntidades->getItem(i)->getPosY()) <= body_futuro.getSize().y)) {
                    if (listaEntidades->getItem(i)->getDanoso()) {
                        // causar dano
                        listaEntidades->getItem(i)->danar();
                    }

                    return true;
                }
            }
        }
    }

    else
        cout << "LISTA VAZIA" << endl;

    return false;
}

bool Gerenciador_Colisoes::colidiuProjetilInimigo(sf::RectangleShape _bodyProjetil, sf::RectangleShape _bodyJogador, int _direcaoDisparo, float _velX) {
    sf::RectangleShape body_futuro;
    body_futuro = _bodyProjetil;
    body_futuro.move(_velX * _direcaoDisparo, gravidade);

    // Se a diferenca entre as distancias em x e em y sao menores que o tamanho do corpo
    if (abs(body_futuro.getPosition().x - _bodyJogador.getPosition().x) <= _bodyJogador.getSize().x &&
        abs(body_futuro.getPosition().y - _bodyJogador.getPosition().y) <= _bodyJogador.getSize().y) {
        return true;
    }
    return false;
}

bool Gerenciador_Colisoes::colidiuProjetilJogador(sf::RectangleShape _bodyProjetil, int _direcaoDisparo, float _velX) {
    sf::RectangleShape body_futuro;
    body_futuro = _bodyProjetil;
    body_futuro.move(_velX * _direcaoDisparo, gravidade);
    
    for (int i = 0; i < listaInimigos->getLength(); i++) {

        if (listaInimigos->getItem(i)->getVivo()) {

            // Se a diferenca entre as distancias em x e em y sao menores que o tamanho do corpo
            if (abs(body_futuro.getPosition().x - listaInimigos->getItem(i)->getPosX()) <= listaInimigos->getItem(i)->getBodySize() &&
                abs(body_futuro.getPosition().y - listaInimigos->getItem(i)->getPosY()) <= listaInimigos->getItem(i)->getBodySize()) {

                // Causa dano ao inimigo
                listaInimigos->getItem(i)->reduzirVida();
                return true;
            }
        }
    }
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

void Gerenciador_Colisoes::setListaInimigos(Lista<Inimigo>* _listaInimigos) {
    listaInimigos = _listaInimigos;
}

void Gerenciador_Colisoes::setListaProjeteis(Lista<Projetil>* _listaProjeteis) {
    listaProjeteis = _listaProjeteis;
}

/*
void Gerenciador_Colisoes::setLO(Plataforma *obstaculo)
{
    LOs->push(obstaculo);
}
//*/