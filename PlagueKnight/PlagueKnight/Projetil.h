#pragma once

#include "Entidade.h"
#include <iostream>

#define VEL_PROJETIL 20.f

using namespace std;

class Projetil : public Entidade {
private:
	int dano;
	bool projetilAtivo;
	sf::FloatRect projetilColisao;
	//time_t tempoAnte = time(NULL);
	//time_t tempoAtual = time(NULL);
	int direcaoDisparoProjetil;

public:
	Projetil();
	Projetil(sf::RenderWindow* _window);
	~Projetil();

	void setDano(int _dano);
	int getDano();

	void setProjetilAtivo(bool _projetilAtivo);
	bool getProjetilAtivo();

	void mover(float _posX, float _posY, int _direcao);
	void draw();
};
