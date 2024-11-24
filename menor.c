#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "ListaSondas.h"

int main() {
    int tipo;
    char linha[500];
    float latitude, longitude, peso;
    char mineral1[50], mineral2[50], mineral3[50];

    printf("1-Arquivo de teste  2-Terminal\n");
    scanf("%d", &tipo);

    if (tipo == 1) {
        TLista_de_Sondas pLista;
        int Qsondas;
        FLSondaVazia(&pLista); // cria uma lista de sondas vazia

        printf("Insira o nome do arquivo de teste: ");
        fflush(stdout);

        char arquivo[50];
        scanf("%49s", arquivo);

        FILE *arq = fopen(arquivo, "r"); // abre o arquivo no modo de leitura
        if (arq == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        fscanf(arq, "%d", &Qsondas);
        printf("%d\n", Qsondas);

        for (int i = 0; i < Qsondas; i++) {
            Sonda_Espacial sonda;
            fscanf(arq, "%f %f %f %f %f", &sonda.latitude, &sonda.longitude, &sonda.Capacidade, &sonda.Velocidade, &sonda.Combustivel);
            InicializarSonda(&sonda, i + 1, sonda.latitude, sonda.longitude, sonda.Capacidade, sonda.Velocidade, sonda.Combustivel);

            if (LSondaInsere(&pLista, &sonda)) {
                printf("Sonda %d inserida com sucesso!\n", sonda.Identificador);
            } else {
                printf("Falha ao inserir a sonda %d.\n", sonda.Identificador);
            }
        }

        printf("Sistema inicializado com %d sondas.\n", Qsondas);

        int Qoperacoes;
        fscanf(arq, "%d", &Qoperacoes);

        for (int i = 0; i < Qoperacoes; i++) {
            char Operac;
            fscanf(arq, " %c", &Operac);

            if (Operac == 'R') {
                fgets(linha, sizeof(linha), arq);
                linha[strcspn(linha, "\n")] = '\0';

                char *token = strtok(linha, " ");
                latitude = atof(token);
                token = strtok(NULL, " ");
                longitude = atof(token);
                token = strtok(NULL, " ");
                peso = atof(token);
                token = strtok(NULL, " ");
                strcpy(mineral1, token ? token : "");
                token = strtok(NULL, " ");
                strcpy(mineral2, token ? token : "");
                token = strtok(NULL, " ");
                strcpy(mineral3, token ? token : "");

                mineral milist;
                strcpy(milist.categoria, "");
                milist.peso = peso;
                milist.latitude = latitude;
                milist.longitude = longitude;

                DadosSonda *sondamaisprox = EncontrarSondaMaisProxima(&pLista, latitude, longitude);
                if (sondamaisprox != NULL) {
                    Move(sondamaisprox, latitude, longitude);
                    printf("Sonda %d movida para a posicao da rocha em (%f, %f).\n", sondamaisprox->Identificador, latitude, longitude);
                    classificacao(&milist, mineral1, mineral2, mineral3);
                    AdicionarRochaNaSondaMaisProxima(&pLista, &milist);
                }
            } else if (Operac == 'I') {
                if (LSondaEhVazia(&pLista)) {
                    printf("A lista de sondas esta vazia.\n");
                } else {
                    LSondaImprime(&pLista);
                }
            } else if (Operac == 'E') {
                OperacaoE(&pLista);
            } else {
                printf("Comando desconhecido: %c\n", Operac);
            }
        }

        fclose(arq);
    } else {
        TLista_de_Sondas pLista;
        int Qsondas;
        FLSondaVazia(&pLista); // cria uma lista de sondas vazia

        printf("Digite a quantidade de sondas: ");
        scanf("%d", &Qsondas);

        for (int i = 0; i < Qsondas; i++) {
            Sonda_Espacial sonda;
            printf("Digite os dados da sonda %d (Latitude Longitude Capacidade Velocidade Combustivel): ", i + 1);
            scanf("%f %f %f %f %f", &sonda.latitude, &sonda.longitude, &sonda.Capacidade, &sonda.Velocidade, &sonda.Combustivel);
            InicializarSonda(&sonda, i + 1, sonda.latitude, sonda.longitude, sonda.Capacidade, sonda.Velocidade, sonda.Combustivel);

            if (LSondaInsere(&pLista, &sonda)) {
                printf("Sonda %d inserida com sucesso!\n", sonda.Identificador);
            } else {
                printf("Falha ao inserir a sonda %d.\n", sonda.Identificador);
            }
        }

        printf("Sistema inicializado com %d sondas.\n", Qsondas);

        printf("Digite a quantidade de operacoes: ");
        int Qoperacoes;
        scanf("%d", &Qoperacoes);

        for (int i = 0; i < Qoperacoes; i++) {
            char Operac;
            printf("Digite o comando (R/I/E): ");
            scanf(" %c", &Operac);

            if (Operac == 'R') {
                char linha[250];
                printf("Digite os dados da nova rocha (Latitude Longitude Peso Mineral1 Mineral2 Mineral3): ");
                fgets(linha, sizeof(linha), stdin);
                linha[strcspn(linha, "\n")] = '\0';

                char *token = strtok(linha, " ");
                latitude = atof(token);
                token = strtok(NULL, " ");
                longitude = atof(token);
                token = strtok(NULL, " ");
                peso = atof(token);
                token = strtok(NULL, " ");
                strcpy(mineral1, token ? token : "");
                token = strtok(NULL, " ");
                strcpy(mineral2, token ? token : "");
                token = strtok(NULL, " ");
                strcpy(mineral3, token ? token : "");

                mineral milist;
                strcpy(milist.categoria, "");
                milist.peso = peso;
                milist.latitude = latitude;
                milist.longitude = longitude;

                DadosSonda *sondamaisprox = EncontrarSondaMaisProxima(&pLista, latitude, longitude);
                if (sondamaisprox != NULL) {
                    Move(sondamaisprox, latitude, longitude);
                    printf("Sonda %d movida para a posicao da rocha em (%f, %f).\n", sondamaisprox->Identificador, latitude, longitude);
                    classificacao(&milist, mineral1, mineral2, mineral3);
                    AdicionarRochaNaSondaMaisProxima(&pLista, &milist);
                }
            } else if (Operac == 'I') {
                if (LSondaEhVazia(&pLista)) {
                    printf("A lista de sondas esta vazia.\n");
                } else {
                    LSondaImprime(&pLista);
                }
            } else if (Operac == 'E') {
                OperacaoE(&pLista);
            } else {
                printf("Comando desconhecido: %c\n", Operac);
            }
        }
    }

    return 0;
}
