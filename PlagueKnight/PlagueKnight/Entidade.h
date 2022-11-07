#pragma once

#include <SFML/Graphics.hpp>

#include "Ente.h"

class Entidade: Ente {
private:

protected:
	float posX;
	float posY;
	float obstSize;
	sf::RectangleShape body;
	sf::RenderWindow* window;

public:
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void imprimir() { window->draw(body); }
	float getBodySize() { return body.getSize().x; }
	void setBodyPosition(float x, float y) { this->body.setPosition(x, y); }
	sf::FloatRect getBodyGlobalBounds() { return this->body.getGlobalBounds(); }
	sf::RectangleShape getBody() { return this->body; }
};

