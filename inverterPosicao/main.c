#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Pilha {
    int topo;
    int elementos[MAX];
};

void inicializar_pilha(struct Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(struct Pilha *p) {
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(struct Pilha *p) {
    if (p->topo == MAX - 1)
        return 1;
    else
        return 0;
}

void push(struct Pilha *p, int valor) {
    if (pilha_cheia(p)) {
        printf("A pilha está cheia.\n");
        return;
    }
    p->topo++;
    p->elementos[p->topo] = valor;
}

int pop(struct Pilha *p) {
    int valor;
    if (pilha_vazia(p)) {
        printf("A pilha está vazia.\n");
        exit(1);
    }
    valor = p->elementos[p->topo];
    p->topo--;
    return valor;
}

void inverter_pilha(struct Pilha *p) {
    struct Pilha aux1, aux2;
    inicializar_pilha(&aux1);
    inicializar_pilha(&aux2);

    while (!pilha_vazia(p)) {
        push(&aux1, pop(p));
    }

    while (!pilha_vazia(&aux1)) {
        push(&aux2, pop(&aux1));
    }

    while (!pilha_vazia(&aux2)) {
        push(p, pop(&aux2));
    }
}

int main() {
    struct Pilha p;
    inicializar_pilha(&p);

    push(&p, 1);
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);

    printf("Pilha original:\n");
    while (!pilha_vazia(&p)) {
        printf("%d\n", pop(&p));
    }

    push(&p, 1);
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);

    inverter_pilha(&p);

    printf("Pilha invertida:\n");
    while (!pilha_vazia(&p)) {
        printf("%d\n", pop(&p));
    }

    return 0;
}
