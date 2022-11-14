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
	sf::RenderWindow* window;

public:
	Entidade();
	~Entidade();
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void draw() { window->draw(body); }
	float getBodySize() { return body.getSize().x; }
	void setBodyPosition(float x, float y) { this->body.setPosition(x, y); }
	sf::FloatRect getBodyGlobalBounds() { return this->body.getGlobalBounds(); }
	sf::RectangleShape getBody() { return this->body; }
	void receberGravidade(bool empuxo);
};

