#include "ListaSondas.h"

typedef struct {
    float x;
    float y;
    Mineral mine;
} RochaS;

void inicializaSistema(TLista_de_Sondas* lista, FILE *arquivo);
void Operacoes(TLista_de_Sondas* lista, FILE* arquivo, Mineral* peso);
void inicioS(TLista_de_Sondas* lista, int num, int identificador, Mponto* compartimento);
float distanciaS(float x1, float y1, float x2, float y2);
void coletarS(TLista_de_Sondas *lista, RochaS *rocha, int num, FILE* arquivo);
void imprimeS(TLista_de_Sondas *lista);
void redistribui(TLista_de_Sondas *lista);
