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
        faseAtiva = true;

        //gc = new Gerenciador_Colisoes(&(listaEntidades->LOs), &(listaEntidades->LIs), &(listaEntidades->LPs));

        //listaEntidades->LJs.push(jogador1);
        inicializaPlataforma();
        inicializaInimigos(_jogador1, _window);
        inicializaProjeteis();
        inicializaArbustoEspinhos();

        /*
        if(listaEntidades.getLength() == 0) {
            cout << "ERRO: listaEntidades vazia na inicializacao." << endl;
        }
        else {
            cout << "Tamanho de listaEntidades em Fase_A: " << listaEntidades.getLength() << "." << endl;
        }
        //*/

        gc->setListaEntidades(&listaEntidades);

        jogador1->setProjetil(bolinha);

        jogador1->setGC(gc);
    }

    void Fase_A::inicializaPlataforma()
    {
        // Plataforma 1º nivel
        for (int i = 0; i < 32; i++)
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
        srand(time(0));
        for (int i = 0; i < 20; i++) {
            Plataforma* plataforma = new Plataforma(((window->getSize().x / 5) + (rand() % 475)), window->getSize().y - 275, window);
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
        unsigned seed = time(0);
        srand(seed);
        qtdInimigos = 0;
        qtdInimigosAtiradores = 0;

        for (int i = 0; i < (3 + (rand() % 3)); i++) {
            Inimigo_A* inimigoA;

            int nivelPlataforma = 1 + (rand() % 3);
            if(nivelPlataforma == 1) {
                inimigoA = new Inimigo_A(150.f + rand() % (window->getSize().x - 150), window->getSize().y - 50, window, jogador1);                listaEntidades.push(inimigoA);
                listaInimigos.push(inimigoA);
            }

            else if (nivelPlataforma == 2 || nivelPlataforma == 3) {
                inimigoA = new Inimigo_A(rand() % 470, window->getSize().y - 175, window, jogador1);
                inimigoA->setLimiteX(0.f, 475.f);
                listaEntidades.push(inimigoA);
                listaInimigos.push(inimigoA);
            }

            /*
            else if (nivelPlataforma == 3) {
                inimigoA = new Inimigo_A((window->getSize().x / 5) + (rand() % 470), window->getSize().y - 300, window, jogador1);
                inimigoA->setLimiteX(window->getSize().x / 5, (window->getSize().x / 5) + 475.f);
                listaEntidades.push(inimigoA);
                listaInimigos.push(inimigoA);
            }
            //*/

            else if (nivelPlataforma == 4) {
                inimigoA = new Inimigo_A(window->getSize().x - 60 * i, window->getSize().y - 425, window, jogador1);
                inimigoA->setLimiteX(window->getSize().x - 475.f, window->getSize().x);
                listaEntidades.push(inimigoA);
                listaInimigos.push(inimigoA);
            }

            else {
                cout << "ERRO: nivel de plataforma para inimigo invalido." << endl;
            }

            qtdInimigos++;
        }

        srand(time(0) + 100);

        for (int i = 0; i < (3 + (rand() % 3)); i++) {
            Inimigo_B* inimigoB;

            int nivelPlataforma = 1 + (rand() % 3);
            if (nivelPlataforma == 1) {
                inimigoB = new Inimigo_B(150.f + rand() % (window->getSize().x - 150), window->getSize().y - 50, window, jogador1);
                listaEntidades.push(inimigoB);
                listaInimigos.push(inimigoB);
            }

            else if (nivelPlataforma == 2 || nivelPlataforma == 3) {
                inimigoB = new Inimigo_B(rand() % 470, window->getSize().y - 175, window, jogador1);
                inimigoB->setLimiteX(0.f, 475.f);
                listaEntidades.push(inimigoB);
                listaInimigos.push(inimigoB);
            }

            /*
            else if (nivelPlataforma == 3) {
                inimigoB = new Inimigo_B((window->getSize().x / 5) + 40 * i, window->getSize().y - 300, window, jogador1);
                inimigoB->setLimiteX(window->getSize().x / 5, (window->getSize().x / 5) + 475.f);
                listaEntidades.push(inimigoB);
                listaInimigos.push(inimigoB);
            }
            //*/

            else if (nivelPlataforma == 4) {
                inimigoB = new Inimigo_B(window->getSize().x - 60 * i, window->getSize().y - 425, window, jogador1);
                inimigoB->setLimiteX(window->getSize().x - 475.f, window->getSize().x);
                listaEntidades.push(inimigoB);
                listaInimigos.push(inimigoB);
            }

            else {
                cout << "ERRO: nivel de plataforma para inimigo invalido." << endl;
            }
            
            qtdInimigos++;
            qtdInimigosAtiradores++;
        }
    }

    void Fase_A::inicializaProjeteis() {
        bolinha = new Projetil(window);
        /*
        listaEntidades.push(bolinha);
        listaProjeteis.push(bolinha);
        //*/

        // Projeteis de inimigos B
        for (int i = 0; i < qtdInimigosAtiradores; i++) {
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

    void Fase_A::inicializaArbustoEspinhos() {
        srand(time(0));
        for (int i = 0; i < (3 + (rand() % 3)); i++) {
            Arbusto_de_Espinhos* arbusto = new Arbusto_de_Espinhos(window->getSize().x - 475.f + (rand() % 400), window->getSize().y - 425, window);

            listaEntidades.push(arbusto);
        }
    }
}