#include <stdio.h>
#include <stdlib.h>


#define TAMANHO_PILHA 10

struct Pilha {
    int topo;
    int valores[TAMANHO_PILHA];
};

void empilhar(struct Pilha *p, int valor) {
    if (p->topo < TAMANHO_PILHA) {
        p->valores[p->topo] = valor;
        p->topo++;
    } else {
        printf("Erro: Pilha cheia.\n");
    }
}

int desempilhar(struct Pilha *p) {
    if (p->topo > 0) {
        p->topo--;
        return p->valores[p->topo];
    } else {
        printf("Erro: Pilha vazia.\n");
        return -1;
    }
}

void transferir_pilha(struct Pilha *p1, struct Pilha *p2) {
    int valor;

    while (p1->topo > 0) {
        valor = desempilhar(p1);
        empilhar(p2, valor);
    }
}

int main() {
    struct Pilha p1 = {0};
    struct Pilha p2 = {0};

    // inserir alguns valores na pilha p1
    empilhar(&p1, 1);
    empilhar(&p1, 2);
    empilhar(&p1, 3);

    // transferir os valores da pilha p1 para a pilha p2
    transferir_pilha(&p1, &p2);

    // imprimir os valores da pilha p2
    while (p2.topo > 0) {
        printf("%d\n", desempilhar(&p2));
    }

    return 0;
}

