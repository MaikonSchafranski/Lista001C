#include <stdio.h>
#include <string.h>
#define TAM_MAX 100

typedef struct {
    int topo;
    char dados[TAM_MAX];
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, char c) {
    if (p->topo >= TAM_MAX-1) {
        return 0;
    }
    p->topo++;
    p->dados[p->topo] = c;
    return 1;
}

int desempilhar(Pilha *p, char *c) {
    if (p->topo < 0) {
        return 0;
    }
    *c = p->dados[p->topo];
    p->topo--;
    return 1;
}

int pilhaVazia(Pilha *p) {
    return (p->topo < 0);
}

int ehPalindromo(char *texto) {
    int i;
    char c, letra;
    Pilha p;

    inicializarPilha(&p);

    for (i = 0; texto[i] != '\0'; i++) {
        letra = tolower(texto[i]);
        if (letra != ' ' && letra != '.') {
            empilhar(&p, letra);
        }
    }

    for (i = 0; texto[i] != '\0'; i++) {
        letra = tolower(texto[i]);
        if (letra != ' ' && letra != '.') {
            desempilhar(&p, &c);
            if (c != letra) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    char texto[TAM_MAX];

    printf("Digite um texto: ");
    fgets(texto, TAM_MAX, stdin);

    if (ehPalindromo(texto)) {
        printf("O texto e um palindromo.\n");
    } else {
        printf("O texto nao e um palindromo.\n");
    }

    return 0;
}
