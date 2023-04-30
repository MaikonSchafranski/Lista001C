#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include "pilha.h"

bool p1_tem_mais_elementos(Pilha* p1, Pilha* p2) {
    int tam_p1 = tamanho(p1);
    int tam_p2 = tamanho(p2);

    return (tam_p1 > tam_p2);
}
