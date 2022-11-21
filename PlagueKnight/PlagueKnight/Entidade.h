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
	bool danoso;

public:
	// Construtoras e Destrutoras
	Entidade();
	~Entidade();

	// Inicializa Variaveis
	void inicializa(float _posX, float _posY, float _obstSize, sf::RenderWindow* _window);

	// Janela
	virtual void setWindow(sf::RenderWindow* window) { this->window = window; }
	virtual void draw() { window->draw(body); }

	// Corpo
	float getBodySize() { return body.getSize().x; }
	void setBodyPosition(float x, float y) { this->body.setPosition(x, y); }
	sf::FloatRect getBodyGlobalBounds() { return this->body.getGlobalBounds(); }
	sf::RectangleShape getBody() { return this->body; }

	// Gravidade
	void receberGravidade(bool empuxo);

	// Posicao
	float getPosX();
	float getPosY();

	// Danoso
	void setDanoso(bool _danoso);
	bool getDanoso();

	virtual void mover(float _posX, float _posY, int _direcao) {}
};

