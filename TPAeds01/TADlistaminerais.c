#include <stdio.h>
#include <string.h>
#include "TADlistaminerais.h"

void vazia(Mlista* lista){
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}
int insere(Mlista* lista, Mineral x){
    if(lista->ultimo==50){
        return 0;
    }else{
        lista->listminerais[lista->ultimo++] = x;
        return 1;
    }
}
int retira(Mlista* lista, char* Nome, Mineral *px) {
    for (int i = 0; i < lista->ultimo; i++) {
        if (strcmp(lista->listminerais[i].Nome, Nome) == 0) {
            *px = lista->listminerais[i];
            lista->ultimo--;
            for (int j = i; j < lista->ultimo; j++) {
                lista->listminerais[j] = lista->listminerais[j + 1];
            }
            return 1;
        }
    }
    return 0;
}
void imprime(Mlista* lista){
    for(int j=lista->primeiro;j<lista->ultimo;j++){
        printf("%s\n",lista->listminerais[j].Nome);
    }
}
