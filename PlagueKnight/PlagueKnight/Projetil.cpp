#include "Projetil.h"

Projetil::Projetil() {
	body.setFillColor(sf::Color::Magenta);
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
	if(this->getPosX() <= (window->getSize().x + 10.f) && _posY <= window->getSize().y)
		this->setBodyPosition(10.f, _posY);
}