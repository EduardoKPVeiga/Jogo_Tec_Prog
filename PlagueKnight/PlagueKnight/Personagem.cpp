#include "Personagem.h"

namespace Personagens {
    Personagem::Personagem() {}

    Personagem::Personagem(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, sf::RenderWindow* w, int num_v) :
        Entidade(x_inicial, y_inicial, caminho_textura, largura, comprimento, w) {
        num_vidas = num_v;
    }

    Personagem::~Personagem() {}

    void Personagem::setNumVidas(int num_v) {
        num_vidas = num_v;
    }

    int Personagem::getVidas() {
        return num_vidas;
    }

    void Personagem::setAlturaMaxPulo(float h) {
        alturaMaxPulo = h;
    }

    float Personagem::getAlturaMaxPulo() {
        return alturaMaxPulo;
    }

    void Personagem::setVelocidade(float v) {
        this->velocidade = v;
    }
}