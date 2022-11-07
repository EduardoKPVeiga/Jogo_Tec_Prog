#include "Ente.h"

Ente::Ente() { id = -1; }

Ente::~Ente() {}

int Ente::getId() {
	return id;
}

void Ente::setId(int i) {
	id = i;
}