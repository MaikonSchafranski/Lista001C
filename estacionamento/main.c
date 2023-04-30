#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ALAMEDA 10

typedef struct carro {
    char placa[8];
    int manobras;
} Carro;

Carro alameda[TAM_ALAMEDA];
int vagas_disponiveis = TAM_ALAMEDA;

void entrada(char placa[]) {
    if (vagas_disponiveis == 0) {
        printf("Sem vagas disponiveis para o carro %s\n", placa);
        return;
    }

    int i;
    for (i = 0; i < TAM_ALAMEDA; i++) {
        if (alameda[i].placa[0] == '\0') {
            strcpy(alameda[i].placa, placa);
            vagas_disponiveis--;
            printf("Carro %s estacionado na vaga %d\n", placa, i + 1);
            break;
        }
    }
}

void saida(char placa[]) {
    int i;
    for (i = 0; i < TAM_ALAMEDA; i++) {
        if (strcmp(alameda[i].placa, placa) == 0) {
            alameda[i].placa[0] = '\0';
            vagas_disponiveis++;

            printf("Carro %s retirado da vaga %d com %d manobras\n", placa, i + 1, alameda[i].manobras);
            alameda[i].manobras = 0;

            int j;
            for (j = i + 1; j < TAM_ALAMEDA && alameda[j].placa[0] != '\0'; j++) {
                strcpy(alameda[j - 1].placa, alameda[j].placa);
                alameda[j].placa[0] = '\0';
                alameda[j - 1].manobras = alameda[j].manobras + 1;
            }

            break;
        }
    }
}

int main() {
    char tipo;
    char placa[8];

    while (scanf(" %c %s", &tipo, placa) != EOF) {
        if (tipo == 'E') {
            entrada(placa);
        } else if (tipo == 'S') {
            saida(placa);
        } else {
            printf("Entrada invalida: %c\n", tipo);
        }
    }

    return 0;
}
