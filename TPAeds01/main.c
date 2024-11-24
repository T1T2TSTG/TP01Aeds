#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "teste.h"

int main() {
    FILE *arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    printf("Arquivo aberto com sucesso\n");
    TLista_de_Sondas lista;
    inicializaSistema(&lista, arquivo);
    //LSondaImprime(&lista);
    fclose(arquivo);
    printf("\nArquivo fechado com sucesso\n");
    return 0;
}
