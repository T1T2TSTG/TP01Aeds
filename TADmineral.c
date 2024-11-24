#include "Tadmineral.h"
#include <string.h>

void inicializa(Mineral *minerio,char *Nome,float Dureza,float Reatividade,char *Cor){
    set_Nome(minerio,Nome);
    set_Dureza(minerio,Dureza);
    set_Reatividade(minerio,Reatividade);
    set_Cor(minerio,Cor);
}

char* get_Nome(Mineral* minerio){
    return(*minerio).Nome;
}
float get_Dureza(Mineral* minerio){
    return(*minerio).Dureza;
}
float get_Reatividade(Mineral* minerio){
    return(*minerio).Reatividade;
}
char* get_Cor(Mineral* minerio){
    return(*minerio).Cor;
}
void set_Nome(Mineral* minerio,char *Nome){
    strcpy((*minerio).Nome,Nome);
}
void set_Dureza(Mineral* minerio, float Dureza){
    (*minerio).Dureza=Dureza;
}
void set_Reatividade(Mineral* minerio, float Reatividade){
    (*minerio).Reatividade=Reatividade;
}
void set_Cor(Mineral* minerio, char *Cor){
    strcpy((*minerio).Cor,Cor);
}
