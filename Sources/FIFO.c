#include "Headers/FIFO.h"
#include <unistd.h>
#include <stdbool.h>
#define cantidad 24



void FIFO() {
    printf("\n\n ALGORITMO FIFO\n\n"); 
    mostrarPaginas();
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
        
    ArrayE[1] = faults;
    ArrayT[1] = ((float) faults / (float) n); 
    printf("\n\nNumero de fallos de pagina = %d\n", faults); 
    printf("\nTasa de fallas de pagina = %f\n\n\n\n", ((float) faults / (float) n));
}