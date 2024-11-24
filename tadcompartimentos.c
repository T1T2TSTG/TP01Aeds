#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tadcompartimentos.h"

void vaziac(Lrochas* lista){
    lista->primeiro=NULL;
    lista->ultimo=NULL;
    lista->tamanho=0;
}
int covaziac(Lrochas* lista){
    return(lista->primeiro == lista->ultimo);
}
int inserec(Lrochas* lista,mineral *px, float maxpeso){ //maxpeso o usuario escolhe
    aponta atual = lista->primeiro;  //começa a busca
    while (atual != NULL){
        if(atual->compartimento==px){ //se ele ja tiver, não adiciona
            return 0;
        }
        atual = atual->prox;
    }
    if(px->peso>maxpeso){ //se ja tiver no max, não procede
        return 0;
    }
    lista->ultimo->prox = (aponta)malloc(sizeof(Mponto)); //aqui adiciona na lista
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->compartimento = px;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
    return 1;
}
int retirac(Lrochas* lista, char* categoria) {
    if (covaziac(lista)) {
        return 0;
    }
    aponta atual = lista->primeiro;
    aponta anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->compartimento->categoria, categoria) == 0) {
            if (anterior == NULL) {
                lista->primeiro = atual->prox;
                if (lista->primeiro == NULL) {
                    lista->ultimo = NULL;
                }
            } else {
                anterior->prox = atual->prox;
                if (atual->prox == NULL) {
                    lista->ultimo = anterior;
                }
            }
            free(atual);
            lista->tamanho--;
            atual = (anterior == NULL) ? lista->primeiro : anterior->prox; // atualiza 'atual' após remoção
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return 0;
}
int imprimec(Lrochas* lista){
    if(covaziac(lista)){
        printf("Compartimento vazio");
        return 0;
    }else{
        aponta aux;
        aux = lista->primeiro->prox;
        while(aux != NULL){
            printf("%d\n", aux->compartimento->Identificador); //não sei se é o identificador mesmo
            aux = aux->prox;
        }
        return 1;
    }
}
int tamanhoc(Lrochas* lista){
    return(lista->tamanho);
}
float pesoc(Lrochas* lista){
    float total=0;
    aponta atual = lista->primeiro; //começa com o primeiro
    while(atual != NULL){
        total+=atual->compartimento->peso; //diferente de null, soma.
        atual=atual->prox;
    }
    return total;
}
int trocarc(Lrochas* lista,mineral *novo){
    aponta atual = lista->primeiro; //inicia
    aponta pesa = NULL;
    while(atual != NULL){
        if(atual->compartimento->categoria == novo->categoria){ //se as categorias forem iguais
            if(pesa==NULL || atual->compartimento->peso < pesa->compartimento->peso){ // se o atual for maior que o novo, troca pelo novo.
                pesa = atual;
            }
        }
        atual = atual->prox; //gira tds
    }
    if(pesa != NULL && novo->peso < pesa->compartimento->peso){
        pesa->compartimento = novo; //pega o mais leve
        return 1;
    }
    return 0;
}
