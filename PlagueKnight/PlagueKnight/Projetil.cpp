#include "Projetil.h"

Projetil::Projetil() {
	body.setFillColor(sf::Color::Magenta);
	time(&tempoAnte);
	time(&tempoAtual);
}

Projetil::~Projetil() {}

void Projetil::setDano(int _dano) {
	dano = _dano;
}

int Projetil::getDano() {
	return dano;
}

void Projetil::setProjetilAtivo(bool _projetilAtivo) {
	projetilAtivo = _projetilAtivo;
}

bool Projetil::getProjetilAtivo() {
	return projetilAtivo;
}

void Projetil::moverProjetil(float _posY) {
	time(&tempoAtual);

	if(!projetilAtivo) // Se o projetil nao foi lancado, nao ha 'tempo de voo'
		tempoAnte = tempoAtual;

	if (this->getPosX() <= (window->getSize().x + 10.f) && _posY <= window->getSize().y) {
		posY = _posY - ((gravidade * powf(float(tempoAtual - tempoAnte), 2)) / 2); // delta_y = (g * (t ^ 2))/2
		this->setBodyPosition(10.f, posY);
		tempoAnte = tempoAtual;
	}
}