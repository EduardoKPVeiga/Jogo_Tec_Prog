#pragma once

#include "Entidade.h"

class Projetil : public Entidade {
private:
	int dano;
	bool projetilAtivo;
	sf::FloatRect projetilColisao;

public:
	Projetil();
	~Projetil();

	void setDano(int _dano);
	int getDano();

	void setProjetilAtivo(bool _projetilAtivo);
	bool getProjetilAtivo();

	void moverProjetil(float _posY);
};

