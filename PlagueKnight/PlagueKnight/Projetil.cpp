#include "Projetil.h"

Projetil::Projetil() {
	body.setFillColor(sf::Color::Magenta);
	body.setSize(sf::Vector2f(5.f, 5.f));
	projetilAtivo = false;
	//time(&tempoAnte);
	//time(&tempoAtual);
}

Projetil::Projetil(sf::RenderWindow* _window) {
	setWindow(_window);
	body.setFillColor(sf::Color::Magenta);
	body.setSize(sf::Vector2f(10.f, 7.f));
	projetilAtivo = false;
	//time(&tempoAnte);
	//time(&tempoAtual);
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

void Projetil::mover(float _posX, float _posY, int _direcao) {
	if (_posX <= window->getSize().x && _posX >= 0.f) {
		if (_posY <= window->getSize().y && _posY >= 0.f) {
			//time(&tempoAtual);

			if (!projetilAtivo) { // Se o projetil nao foi lancado, nao ha 'tempo de voo'
				//tempoAnte = tempoAtual;
				//cout << "Projetil Desativo." << endl;
				body.setPosition(_posX, _posY);
				direcaoDisparoProjetil = _direcao;
				posX = _posX;
				posY = _posY;
			}

			if (projetilAtivo) {
				//cout << "Projetil Ativo." << endl;
				if ((_direcao == 1 && posX <= (window->getSize().x + 10.f)) || (_direcao == -1 && posX >= 10.f)) {
					//tempoAnte = tempoAtual;

					posX += (5.f * direcaoDisparoProjetil);
					//posY += float((gravidade * powf(float(tempoAtual - tempoAnte), 2)) / 2.f);
					posY += 0.1f;
					body.setPosition(posX, posY);
					//body.move(VEL_PROJETIL * direcaoDisparoProjetil, gravidade / 2);
					//cout << "Y: " << body.getPosition().y << endl;

					// Se o projetil saiu da tela, desativa
					if ((body.getPosition().x > window->getSize().x || body.getPosition().x < 10.f) || (body.getPosition().y > window->getSize().y || body.getPosition().y < 0.f))
						projetilAtivo = false;
				}
			}

		}
		else {
			cout << "ERRO! Posicao Y invalida." << endl;
			return;
		}
	}
	else {
		cout << "ERRO! Posicao X invalida." << endl;
		return;
	}
}

void Projetil::draw() {
	if (projetilAtivo)
		window->draw(body);
}