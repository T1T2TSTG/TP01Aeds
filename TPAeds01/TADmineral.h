#ifndef TADMINERAL_H
#define TADMINERAL_H
#include <stdio.h>
typedef struct{
    char Nome[30];
    float Dureza;
    float Reatividade;
    char Cor[20];
}Mineral;

void inicializa(Mineral *minerio,char *Nome,float Dureza,float Reatividade,char *Cor);

char* get_Nome(Mineral* minerio);
float get_Dureza(Mineral* minerio);
float get_Reatividade(Mineral* minerio);
char* get_Cor(Mineral* minerio);

void set_Nome(Mineral* minerio,char *Nome);
void set_Dureza(Mineral* minerio, float Dureza);
void set_Reatividade(Mineral* minerio, float Reatividade);
void set_Cor(Mineral* minerio, char *Cor);

#endif
