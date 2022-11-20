#pragma once

#include "Entidade.h"
#include <iostream>

using namespace std;

class Projetil : public Entidade {
private:
	int dano;
	bool projetilAtivo;
	sf::FloatRect projetilColisao;
	//time_t tempoAnte = time(NULL);
	//time_t tempoAtual = time(NULL);

public:
	Projetil();
	~Projetil();

	void setDano(int _dano);
	int getDano();

	void setProjetilAtivo(bool _projetilAtivo);
	bool getProjetilAtivo();

	void moverProjetil(float _posX, float _posY, int _direcaoDisparo);
};

