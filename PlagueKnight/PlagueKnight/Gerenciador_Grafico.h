#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico {
private:
	sf::Texture texture;

public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();
	void imprimirEnte(float x, float y, const char* textura, const char* cor);
};

