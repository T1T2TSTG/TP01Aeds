#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "teste.h"

void inicializaSistema(TLista_de_Sondas* lista, FILE *arquivo) {
    char linha[20];
    fgets(linha, sizeof(int), arquivo);
    int numSondas = atoi(linha);
    printf("linha lida: %d\n", numSondas);//pra verificaar se leu
    inicioS(lista, numSondas, "identificador_padrao", NULL);
}
/*void Operacoes(TLista_de_Sondas* lista, FILE* arquivo, Mineral* peso) {
    int numOperacoes;
    fscanf(arquivo, "%d", &numOperacoes);
    for (int i = 0; i < numOperacoes; i++) {
        char operacao;
        fscanf(arquivo, " %c", &operacao);
        if (operacao == 'R') {
            RochaS rocha;
            fscanf(arquivo, "%f %f %f %s %s", &rocha.x, &rocha.y, &rocha.mine.Dureza, rocha.mine.Nome, rocha.mine.Cor);
            coletarS(lista, &rocha);
        } else if (operacao == 'I') {
            imprimeS(lista);
        } else if (operacao == 'E') {
            redistribui(lista);
            imprimeS(lista);
        }
    }
}*/
void inicioS(TLista_de_Sondas* lista, int num, int Identificador, Mponto* compartimento) {
    FLSondaVazia(lista);
    float lat = 0;
    float longi = 0;
    for (int i = 0; i < num; i++) {
        Sonda_Espacial sonda;
        //Mponto compartimento;
        vaziac(&compartimento);
        char id[30];
        sprintf(id, "%s_%d", Identificador, i + 1);
        Inicializa_Sonda(&sonda, id, &compartimento, lat, longi);
        Liga(&sonda);
        imprime_Sonda(&sonda);
        LSondaInsere(lista, &sonda);
    }
}
float distanciaS(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
/*void coletarS(TLista_de_Sondas *lista, RochaS *rocha, int num, FILE *arquivo) {// num = numero de sondas
    // receber localização das rochas e comparar com localização de cada sonda usando for.
    Sonda_Espacial* sondaMaisProxima = NULL;
    char linha[20];
    float LatP, LongP;
    fgets(linha, sizeof(linha), arquivo);//pega a linha do arquivo
    sscanf(linha, "%f %f", &LatP, &LongP);//pega localização da pedra
    float menorDistancia = __FLT_MAX__;//variavel com o maior valor possivel de float
    for(int i=0;i<num; i++){
        Sonda_Espacial* sondaAtual = &lista->sondas[i];
        float x1 = get_latitudeSonda;
        float y1 = get_longitudeSonda;
        float distanciaS1 = distanciaS(x1, y1, LatP, LongP);
        if (distanciaS1 < menorDistancia) {
            menorDistancia = distanciaS1;
            sondaMaisProxima = sondaAtual;
    }
}*/
void imprimeS(TLista_de_Sondas *lista) {
    Apontador pAux = lista->pPrimeiro->pProx;
    int index = 1;
    while (pAux != NULL) {
        printf("%d\n", index++);
        imprimec(&pAux->Sonda.compartimento);
        pAux = pAux->pProx;
    }
}
void redistribui(TLista_de_Sondas *lista) {
    Apontador aux = lista->pPrimeiro->pProx;
    float total = 0;
    int N = 0;
    while (aux != NULL) {
        total += pesoc(&aux->Sonda.compartimento);
        N++;
        aux = aux->pProx;
    }
    float mpeso = total / N;
    aux = lista->pPrimeiro->pProx;
    TLista_de_Sondas temporaria;
    FLSondaVazia(&temporaria);
    while (aux != NULL) {
        if (pesoc(&aux->Sonda.compartimento) > mpeso) {
            while (pesoc(&aux->Sonda.compartimento) > mpeso) {
                Mineral mineral;
                retirac(&aux->Sonda.compartimento, &mineral);
                LSondaInsere(&temporaria, &aux->Sonda);
            }
        }
        aux = aux->pProx;
    }
    aux = lista->pPrimeiro->pProx;
    while (aux != NULL) {
        if (pesoc(&aux->Sonda.compartimento) < mpeso) {
            while (pesoc(&aux->Sonda.compartimento) < mpeso && !LSondaEhVazia(&temporaria)) {
                Mineral mineral;
                LSondaRetira(&temporaria, &mineral);
                inserec(&aux->Sonda.compartimento, &mineral, 100);
            }
        }
        aux = aux->pProx;
    }
}
