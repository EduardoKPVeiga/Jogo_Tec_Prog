#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Options.h"
#include "Ente.h"

class Menu : Ente {
private:
	std::vector< std::string> options_str;

public:
	Menu();
	~Menu();
	void select_options(Options* option, sf::RenderWindow* window);
};
