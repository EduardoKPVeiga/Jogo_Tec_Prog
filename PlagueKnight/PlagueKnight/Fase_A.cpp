#include "Fase_A.h"

Fase_A::Fase_A() {}

Fase_A::~Fase_A() {}

void Fase_A::inicializeElementos() {

    // Criando os inimigos da fase
    Inimigo_B* inimigo1 = new Inimigo_B(0.f, 0.f, window);
    Inimigo_B* inimigo2 = new Inimigo_B(650.f, 360.f, window);
    Inimigo_B* inimigo3 = new Inimigo_B(400.f, 0.f, window);
    Inimigo_A* inimigo4 = new Inimigo_A(10.f, 20.f, window);

    // Criando os obstaculos da fase
    Obstaculo* obstaculo1 = new Obstaculo();
    Obstaculo* obstaculo2 = new Obstaculo();
    Obstaculo* obstaculo3 = new Obstaculo();

    // Colocando os inimigos na lista de entidades
    listaEntidades->LEs.push(inimigo1);
    listaEntidades->LEs.push(inimigo2);
    listaEntidades->LEs.push(inimigo3);
    listaEntidades->LEs.push(inimigo4);

    // Colocando os obstaculos na lista de entidades
    listaEntidades->LEs.push(obstaculo1);
    listaEntidades->LEs.push(obstaculo2);
    listaEntidades->LEs.push(obstaculo3);

    // Colocando os inimigos na lista de inimigos
    listaEntidades->LIs.push(inimigo1);
    listaEntidades->LIs.push(inimigo2);
    listaEntidades->LIs.push(inimigo3);
    listaEntidades->LIs.push(inimigo4);
}