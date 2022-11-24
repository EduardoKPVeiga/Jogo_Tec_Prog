#include "Fase_A.h"

namespace Fases {
    Fase_A::Fase_A() {
        inicializeElementos(NULL, NULL);
    }

    Fase_A::Fase_A(Jogador* _jogador1, sf::RenderWindow* _window) {
        inicializeElementos(_jogador1, _window);
    }

    Fase_A::~Fase_A() {}

    void Fase_A::inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window) {
        this->window = _window;
        this->jogador1 = _jogador1;

        //gc = new Gerenciador_Colisoes(&(listaEntidades->LOs), &(listaEntidades->LIs), &(listaEntidades->LPs));

        //listaEntidades->LJs.push(jogador1);
        inicializaPlataforma();
        inicializaInimigos(_jogador1, _window);
        inicializaProjeteis();

        /*
        if(listaEntidades.getLength() == 0) {
            cout << "ERRO: listaEntidades vazia na inicializacao." << endl;
        }
        else {
            cout << "Tamanho de listaEntidades: " << listaEntidades.getLength() << "." << endl;
        }
        //*/

        gc->setListaEntidades(&listaEntidades);

        jogador1->setProjetil(bolinha);

        jogador1->setGC(gc);
    }

    void Fase_A::inicializaPlataforma()
    {
        // Plataforma 1º nivel
        for (int i = 0; i < 44; i++)
        {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 25, window);
            listaEntidades.push(plataforma);
        }

        // Plataformas 2º nivel
        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 150, window);
            listaEntidades.push(plataforma);
        }

        for (int i = 0; i < 7; i++) {
            Plataforma* plataforma = new Plataforma((window->getSize().x - (25 * i)), window->getSize().y - 150, window);
            listaEntidades.push(plataforma);
        }

        // Plataforma 3º nivel
        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma(((window->getSize().x / 5) + (25 * i)), window->getSize().y - 275, window);
            listaEntidades.push(plataforma);
        }

        // Plataformas 4º nivel
        for (int i = 0; i < 7; i++) {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 400, window);
            listaEntidades.push(plataforma);
        }

        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma((window->getSize().x - (25 * i)), window->getSize().y - 400, window);
            listaEntidades.push(plataforma);
        }
    }

    void Fase_A::inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window) {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, window->getSize().y - 50, window, jogador1);
        Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
        Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
        Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);

        inimigo1->setAtirador(true);
        inimigo2->setAtirador(true);
        inimigo3->setAtirador(true);
        inimigo4->setAtirador(false);

        listaEntidades.push(inimigo1);
        listaEntidades.push(inimigo2);
        listaEntidades.push(inimigo3);
        listaEntidades.push(inimigo4);

        listaInimigos.push(inimigo1);
        listaInimigos.push(inimigo2);
        listaInimigos.push(inimigo3);
        listaInimigos.push(inimigo4);

        qtdInimigos = 4;
    }

    void Fase_A::inicializaProjeteis() {
        bolinha = new Projetil(window);
        /*
        listaEntidades.push(bolinha);
        listaProjeteis.push(bolinha);
        //*/

        // Projeteis de inimigos B
        for (int i = 0; i < 3; i++) {
            Projetil* projetil = new Projetil(window);
            listaEntidades.push(projetil);
            listaProjeteis.push(projetil);
        }

        int j = 0;
        for (int i = 0; i < listaInimigos.getLength(); i++) {
            if (listaInimigos.getItem(i)->getAtirador()) {
                listaInimigos.getItem(i)->setProjetil(listaProjeteis.getItem(j));
                j++;
            }
        }

    }
}