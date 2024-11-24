#include <stdlib.h>
#include <stdio.h>
#include "ListaSondas.h"

void FLSondaVazia(TLista_de_Sondas* pLista)
{
 pLista->pPrimeiro = (Apontador) malloc(sizeof(TCelula));
 pLista->pUltimo = pLista->pPrimeiro;
 pLista->pPrimeiro->pProx = NULL;
}
int LSondaEhVazia(TLista_de_Sondas* pLista)
{
 return (pLista->pPrimeiro == pLista->pUltimo);
}
void LSondaInsere(TLista_de_Sondas *pLista,TSonda* pSonda)
{
 pLista->pUltimo->pProx = (Apontador) malloc(sizeof(TCelula));
 pLista->pUltimo = pLista->pUltimo->pProx;
 pLista->pUltimo->Sonda = *pSonda;
 pLista->pUltimo->pProx = NULL;
}
int LSondaRetira(TLista_de_Sondas* pLista, TSonda* pSonda)
{
 TCelula* pAux;
 if (LSondaEhVazia(pLista))
 return 0;
 *pSonda = pLista->pPrimeiro->pProx->Sonda;
 pAux = pLista->pPrimeiro;
 pLista->pPrimeiro = pLista->pPrimeiro->pProx;
 free(pAux);
 return 1;
}
void LSondaImprime(TLista_de_Sondas* pLista)
{
 Apontador pAux;
 pAux = pLista->pPrimeiro->pProx;
 while (pAux != NULL)
 {
 imprime_Sonda(&pAux->Sonda);
 pAux = pAux->pProx;
 }
}


