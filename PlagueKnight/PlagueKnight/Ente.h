#pragma once

class Ente {
private:

protected:
	int id;

public:
	Ente();
	~Ente();

	virtual void executar();
	void imprimir_se();

	int getId();
	void setId(int i);
};

