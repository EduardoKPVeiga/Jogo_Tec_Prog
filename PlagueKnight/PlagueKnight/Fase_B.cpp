#include "Fase_B.h"

namespace Fases {
    Fase_B::Fase_B() {
        inicializeElementos(NULL, NULL);
    }

    Fase_B::Fase_B(Jogador* _jogador1, sf::RenderWindow* _window) {
        inicializeElementos(_jogador1, _window);
    }

    Fase_B::~Fase_B() {}

    void Fase_B::inicializeElementos(Jogador* _jogador1, sf::RenderWindow* _window) {
        this->window = _window;
        this->jogador1 = _jogador1;

        //gc = new Gerenciador_Colisoes(&(listaEntidades->LOs), &(listaEntidades->LIs), &(listaEntidades->LPs));
        gc->setListaEntidades(&listaEntidades);

        //listaEntidades->LJs.push(jogador1);
        inicializaPlataforma();
        inicializaInimigos(_jogador1, _window);
        inicializaProjeteis();

        jogador1->setProjetil(bolinha);

        jogador1->setGC(gc);
    }

    void Fase_B::inicializaPlataforma() {
        // Plataforma 1º nivel
        for (int i = 0; i < 44; i++)
        {
            Plataforma* plataforma = new Plataforma(25 * i, window->getSize().y - 25, window);
            listaEntidades.push(plataforma);
        }
    }

    void Fase_B::inicializaInimigos(Jogador* _jogador1, sf::RenderWindow* _window) {
        Inimigo_B* inimigo1 = new Inimigo_B(0.f, window->getSize().y - 50, window, jogador1);
        Inimigo_B* inimigo2 = new Inimigo_B((650.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
        Inimigo_B* inimigo3 = new Inimigo_B((400.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);
        Inimigo_A* inimigo4 = new Inimigo_A((10.f / RESOLUTION_X), window->getSize().y - 50, window, jogador1);

        inimigo1->setAtirador(true);
        inimigo2->setAtirador(true);
        inimigo3->setAtirador(true);

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

    void Fase_B::inicializaProjeteis() {
        bolinha = new Projetil(window);
        listaEntidades.push(bolinha);
        listaProjeteis.push(bolinha);

        // Projeteis de inimigos B
        for (int i = 0; i < 3; i++) {
            Projetil* projetil = new Projetil(window);
            listaEntidades.push(projetil);
            listaProjeteis.push(projetil);

            if (listaInimigos.getItem(i)->getAtirador()) {
                listaInimigos.getItem(i)->setProjetil(projetil);
            }
        }
    }
}