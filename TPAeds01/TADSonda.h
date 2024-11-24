#ifndef TADSonda_H
#define TADSonda_H
#include "tadcompartimentos.h"

typedef struct {
    int Identificador;
    Mponto* compartimento;
    float latitude;
    float longitude;
    char EstaLigada[6];

} Sonda_Espacial;

void Inicializa_Sonda(Sonda_Espacial *sonda, int Identificador,Mponto* compartimento, float latitude,float longitude);
void Liga(Sonda_Espacial *sonda);
void Desliga(Sonda_Espacial *sonda);
void imprime_Sonda(Sonda_Espacial *sonda);
int get_IdentificadorSonda(Sonda_Espacial *sonda);
float get_latitudeSonda(Sonda_Espacial *sonda);
float get_longitudeSonda(Sonda_Espacial *sonda);
void set_IdentificadorSonda(Sonda_Espacial *sonda, int identificador);
void set_latitudeSonda(Sonda_Espacial *sonda, float latitude);
void set_longitudeSonda(Sonda_Espacial *sonda, float longitude);
void Move(Sonda_Espacial *sonda,FILE *arquivo);
#endif
