#pragma once

#include "Options.h"
#include "Ente.h"
#include "Resolucao.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Menu : Ente {
private:
	std::vector< std::string> options_str;
	int vetorPontos[5] = { 0, 0, 0, 0, 0 };

public:
	Menu();
	~Menu();
	void select_options(Options* option, sf::RenderWindow* window);
	void pushVetorPontos(int _pontos) {
		int aux = 0;
		if (_pontos > vetorPontos[4])
			vetorPontos[4] = _pontos;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				if (vetorPontos[j] < vetorPontos[j + 1]) {
					aux = vetorPontos[j];
					vetorPontos[j] = vetorPontos[j + 1];
					vetorPontos[j + 1] = aux;
				}
			}
		}
	}
};
