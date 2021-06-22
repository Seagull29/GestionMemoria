#include "Headers/FIFO.h"
#include "Algoritmos.c"
#include <stdbool.h>
#include <stdio.h>

int cantidad = 24;

void FIFO_p() {
    printf("\n\n ALGORITMO FIFO\n\n"); 
    //mostrarPaginas();
    int n, f, faults = 0, count; 
    int marcos[3] = {0, 0, 0}; 
    int referencias[30] = {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9};
    int i, j, k = 0; n = 25; f = 3; count = 1; 
    bool found = false;
    printf("\t\t M1\tM2\tM3\tFallos\n");
    
    /* Procesamiento */
    for (i = 0; i < n; i++) {
    /* Busca por cada pagina */ 
        for (j = 0; j < f; j++) { 
            if (referencias[i] == marcos[j]) {
                found = true;
            }
        }
        if (found == false) {
            marcos[k] = referencias[i];
            if (k == f - 1) { 
                k = 0; 
            } else { 
                k++; 
            } 
            faults++;
        }
        /* Imprimir */ 
        printf("Tiempo %d-> (%d)\t:", count, referencias[i]); 
        for (j = 0; j < f; j++)
            printf("%d\t", marcos[j]);
        
        // Si hay fallo
        if (!found)
            printf("Fallo");
        
        printf("\n"); 
        count++;
        found = true;
    } 
        
    printf("\n\nNumero de fallos de pagina = %d\n", faults); 
    printf("\nTasa de fallas de pagina = %f\n\n\n\n", ((float) faults / (float) n));
}



void FIFO() {

    int referencias[] = {2, 3, 2, 1, 5, 2, 4 ,5, 3, 2 , 5, 2, 8, 6, 2, 2, 7, 4, 1, 5, 9, 6, 3, 7, 9};
    int marcos[] = {0, 0, 0}, i = 0, j;
    int primero = 0, fallos = 0, hay = 0;
    printf("Tiempo:\tReferencia:\tMarco 1:\tMarco 2:\tMarco 3:\tFallos:\t\n");
    while (i < cantidad) {
        hay = 0;
        for (j = 0; j < 3; ++j) {
            if (marcos[j] == 0) {
                marcos[j] = referencias[i];
                ++fallos;
                hay = 1;
                break; 
            }
            if (referencias[i] == marcos[j]) {
                break;
            }
            if (j == 2) {
                marcos[primero++] = referencias[i];
                ++fallos;
                hay = 1;
            }
        }

        if (primero == 3) {
            primero = 0;
        }

        Imprimir(referencias, marcos, hay, i);
        ++i; 
        
       
    }

    for (i = 0; i < 3; i++) {
        printf("%d\n", marcos[i]);
    }
    printf("Numero de fallos: %d\n", fallos);
    printf("Tasa de fallos: %.2f\n", (double) 24 / fallos);
    
    

}