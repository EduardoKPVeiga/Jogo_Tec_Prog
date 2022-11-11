#pragma once

#include <SFML/Graphics.hpp>

#include "Ente.h"

class Entidade : public Ente {
private:

protected:
	float posX;
	float posY;
	float obstSize;
	sf::RectangleShape body;
	sf::Texture* textura;
	sf::RenderWindow* window;

public:
	Entidade();
	Entidade(float x_inicial, float y_inicial, const char* caminho_textura, float largura, float comprimento);
	~Entidade();
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void draw() { window->draw(body); }
	float getBodySize() { return body.getSize().x; }
	void setBodyPosition(float x, float y) { this->body.setPosition(x, y); }
	sf::FloatRect getBodyGlobalBounds() { return this->body.getGlobalBounds(); }
	sf::RectangleShape getBody() { return this->body; }
};

