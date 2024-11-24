#include "TADmineral.h"
#ifndef TADLISTAMINERAIS_H
#define TADLISTAMINERAIS_H

typedef struct{
    Mineral listminerais[50];
    int primeiro, ultimo;
}Mlista;

void vazia(Mlista* lista);
int insere(Mlista* lista, Mineral x);
int retira(Mlista* lista, char* Nome, Mineral *px);
void imprime(Mlista* lista);

#endif
