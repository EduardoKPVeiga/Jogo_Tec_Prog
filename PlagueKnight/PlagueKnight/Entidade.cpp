#include "Entidade.h"

Entidade::Entidade() :body(sf::Vector2f(50.f, 50.f)) {
	inicializa(0, 0, 0, 0);
}

Entidade::Entidade(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, sf::RenderWindow* w) {
	inicializa(x_inicial, y_inicial, NULL, w);

	body.setPosition(posX, posY); // ?

	body.setSize(sf::Vector2f(largura, comprimento));

	
	textura->loadFromFile(caminho_textura);
}

Entidade::~Entidade() {}

void Entidade::inicializa(float _posX, float _posY, float _obstSize, sf::RenderWindow* _window) {
	obstSize = _obstSize;
	this->window = _window;
	posX = _posX;
	posY = _posY;
	textura = new sf::Texture;
}

void Entidade::receberGravidade(bool empuxo)
{
	if (!empuxo)
	{
		this->body.move(sf::Vector2f(0.0f, gravidade));
	}
	else
	{
		this->body.move(sf::Vector2f(0.0f, gravidade-gravidade));
	}
}
