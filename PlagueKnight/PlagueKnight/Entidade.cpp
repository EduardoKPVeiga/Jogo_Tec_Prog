#include "Entidade.h"

Entidade::Entidade() : body(sf::Vector2f(50.f, 50.f)) {
	obstSize = NULL;
	posX = NULL;
	posY = NULL;
	window = NULL;
}

Entidade::Entidade(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento) {
	posX = x_inicial;
	posY = y_inicial;

	body.setSize(sf::Vector2f(largura, comprimento));

	textura = new sf::Texture;
	textura->loadFromFile(caminho_textura);
}

Entidade::~Entidade() {
	delete textura;
}