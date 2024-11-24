#ifndef LISTASONDAS_H
#define LISTASONDAS_H
#include "TADSonda.h"

typedef Sonda_Espacial TSonda;
typedef struct Celula* Apontador;
typedef struct Celula {
 TSonda Sonda;
 Apontador pProx;
} TCelula;
typedef struct {
 Apontador pPrimeiro;
 Apontador pUltimo;
} TLista_de_Sondas;

void FLSondaVazia(TLista_de_Sondas* pLista);
int LSondaEhVazia(TLista_de_Sondas* pLista);
void LSondaInsere(TLista_de_Sondas* pLista, TSonda *pSonda);
int LSondaRetira(TLista_de_Sondas* pLista, TSonda *pSonda);
void LSondaImprime(TLista_de_Sondas* pLista);
#endif

