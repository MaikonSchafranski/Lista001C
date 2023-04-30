#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;


void initialize(Stack *s) {
    s->top = -1;
}


void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Erro: pilha cheia!\n");
        exit(1);
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}


int pop(Stack *s) {
    if (s->top == -1) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    } else {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}

int equal(Stack *s1, Stack *s2) {

    if (s1->top != s2->top) {
        return 0;
    }

    Stack aux1, aux2;
    initialize(&aux1);
    initialize(&aux2);


    while (s1->top != -1) {
        push(&aux1, pop(s1));
        push(&aux2, pop(s2));
    }


    while (aux1.top != -1) {
        int value1 = pop(&aux1);
        int value2 = pop(&aux2);
        if (value1 != value2) {
            return 0;
        }
    }


    return 1;
}


int main() {

    Stack s1, s2;
    initialize(&s1);
    initialize(&s2);


    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);

    push(&s2, 1);
    push(&s2, 2);
    push(&s2, 3);


    if (equal(&s1, &s2)) {
        printf("As pilhas sao iguais.\n");
    } else {
        printf("As pilhas sao diferentes.\n");
    }

    return 0;
}
