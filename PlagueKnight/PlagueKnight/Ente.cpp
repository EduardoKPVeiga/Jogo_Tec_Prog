#include "Ente.h"

Ente::Ente() { id = -1; }

Ente::~Ente() {}

void Ente::executar() {}

void Ente::imprimir_se() {}

int Ente::getId() {
	return id;
}

void Ente::setId(int i) {
	id = i;
}