#include "Headers/algoritmos.h"
#include <stdio.h>

void Imprimir(int * referencias, int * marcos, int hay, int i) {
    if (hay) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\tFallo\n", i + 1, referencias[i], marcos[0], marcos[1], marcos[2]);
    } else {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n", i + 1, referencias[i], marcos[0], marcos[1], marcos[2]);
    }
}

void Imprimir_es(int * referencias, Pagina * marcos, int hay, int i) {
    if (hay) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\tFallo\n", i + 1, referencias[i], marcos[0].numero, marcos[1].numero, marcos[2].numero);
    } else {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n", i + 1, referencias[i], marcos[0].numero, marcos[1].numero, marcos[2].numero);
    }
}



