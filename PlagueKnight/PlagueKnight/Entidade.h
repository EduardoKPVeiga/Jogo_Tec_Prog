#pragma once

#include <SFML/Graphics.hpp>

#include "Ente.h"

class Entidade : public Ente {
private:

protected:
	float posX;
	float posY;
	float obstSize;
	float gravidade = 10.0f;
	bool empuxo = false;
	sf::RectangleShape body;
	sf::Texture* textura;
	sf::RenderWindow* window;

public:
	// Construtoras e Destrutoras
	Entidade();
	Entidade(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento, sf::RenderWindow* window);
	~Entidade();

	// Inicializa Variaveis
	void inicializa(float _posX, float _posY, float _obstSize, sf::RenderWindow* _window);

	// Janela
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void draw() { window->draw(body); }

	// Corpo
	float getBodySize() { return body.getSize().x; }
	void setBodyPosition(float x, float y) { this->body.setPosition(x, y); }
	sf::FloatRect getBodyGlobalBounds() { return this->body.getGlobalBounds(); }
	sf::RectangleShape getBody() { return this->body; }

	// Gravidade
	void receberGravidade(bool empuxo);

	// Posicao
	void setPosXY(float _posX, float _posY);
	void setPosX(float _posX);
	void setPosY(float _posY);
	float getPosX();
	float getPosY();
};

