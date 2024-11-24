#ifndef TADCOMPARTIMENTOS_H
#define TADCOMPARTIMENTOS_H
#include "rochamineral.h"
#include <stdlib.h>

typedef struct ponto* aponta;
typedef struct ponto{
    mineral *compartimento;
    struct ponto* prox;
} Mponto;

typedef struct{
    aponta primeiro;
    aponta ultimo;
    int tamanho;
}Lrochas;

void vaziac(Lrochas* lista);
int covaziac(Lrochas* lista);
int inserc(Lrochas* lista, mineral *px, float maxpeso); //não pode ter rochas repetidas com peso maior que a capacidade
int retirac(Lrochas* lista, char* categoria); //pela categoria
int imprimec(Lrochas* lista); //indicar quando tiver vazia
int tamanhoc(Lrochas* lista);//numero atual de rochas
float pesoc(Lrochas* lista); //peso do compartimento
int trocarc(Lrochas* lista,mineral *novo); //adiciona uma rocha leve no lugar da pesada do mesmo tipo

#endif
