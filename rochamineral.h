#include "TADlistaminerais.h"

typedef struct{
    Mineral* listminerais;
    int Identificador;
    float peso;
    char categoria[50];
    float latitude;
    float longitude;
    char data;
}mineral;

void inicializar(mineral* milist,float peso,float latitude,float longitude,char *data,int Identificador);

int get_Identificador(mineral* milist);
float get_peso(mineral* milist);
float get_longitude(mineral* milist);
float get_latitude(mineral* milist);
char* get_data(mineral* milist);

void set_Identificador(mineral* milist,int Identificador);
void set_peso(mineral* milist, float peso);
void set_longitude(mineral* milist, float longitude);
void set_latitude(mineral* milist, float latitude);
void set_data(mineral* milist, char *data);

void listminerais(mineral* milist,Mineral* listminerais);
void classificacao(mineral* milist,char *categoria,Mineral* listminerais);
