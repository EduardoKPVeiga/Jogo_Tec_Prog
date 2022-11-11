#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico() {}

Gerenciador_Grafico::~Gerenciador_Grafico() {}

void Gerenciador_Grafico::imprimirEnte(float x, float y, const char* textura, const char* cor) {
	sf::RectangleShape shape(sf::Vector2f(x, y));
	shape.setFillColor(sf::Color::Green);
	texture.loadFromFile(textura);

	
}
