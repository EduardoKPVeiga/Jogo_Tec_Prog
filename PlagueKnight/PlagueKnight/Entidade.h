#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

class Gerenciador_Colisoes;
class Entidade : public Ente {
private:

protected:
	float posX;
	float posY;
	float obstSize;
	float gravidade = 10.0f;
	bool empuxo = false;
	bool atirador;
	sf::RectangleShape body;
	sf::RenderWindow* window;
	bool danoso;
	bool vivo;

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
	float getPosX();
	float getPosY();
	virtual void mover(float _posX, float _posY, int _direcao) {}
	void setAtirador(bool _atirador) { atirador = _atirador; }
	bool getAtirador() { return atirador; }
	virtual void atirar() {}
	void setDanoso(bool _danoso);
	bool getDanoso();
	void setVivo(bool _vivo);
	bool getVivo();
	virtual void danar();
};

