#include <stdlib.h>
#include <stdio.h>
#include "Headers/LRU.h"
#include "Algoritmos.c"

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }   
    }
    //return minimum[0];
} 


void LRU_o() {
    printf("\n\n ALGORITMO LRU \n\n"); 

    int marcos;
    int referencias; 
    int frames[10], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    // Variables estaticas 
    marcos = 3; referencias = 25; 
    int pages[30] = {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9};
    
   /* int findLRU(int time[], int n) {
        int i, minimum = time[0], pos = 0;
        for (i = 1; i < n; ++i) {
            if (time[i] < minimum) {
                minimum = time[i];
                pos = i;
            }   
        }
        return minimum[0];
    } */
    
    // Inicializar en vacio 
    for (i = 0; i < marcos; ++i) {
        frames[i] = 0;
    }
    printf("\t\t M1\tM2\tM3\t Fallos\n");
    /* Procesamiento */ 
    for (i = 0; i < referencias; ++i) { 
        flag1 = flag2 = 0;
        for (j = 0; j < marcos; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0) { 
            for (j = 0; j < marcos; ++j) { 
                if (frames[j] == 0) {
                    counter++; faults++;
                    frames[j] = pages[i];
                    time[j] = counter; flag2 =1; 
                    break;
                }
            }
        }
        if (flag2 == 0) { 
            pos = findLRU(time, marcos); 
            counter++; faults++;
            frames[pos] = pages[0];
            time[pos] = counter;
        }
        /* Imprimir */ 
        printf("Tiempo %d-> (%d)\t:", i+1, pages[i]);
        for (j = 0; j < marcos; ++j) 
            printf("%d\t", frames[j]); 
        // Si hay fallo 
        if (flag2 == 0) 
            printf("Fallo");
        printf("\n");
    }
    float tasa = ((float) faults / (float) referencias);
    
    printf("\n\nTotal de fallas de pagina = %d", faults);
    printf("\n\nTasa de fallas de pagina = %f \n\n\n\n", tasa);
}

void LRU() {

    int referencias[] = {2, 3, 2, 1, 5, 2, 4 ,5, 3, 2 , 5, 2, 8, 6, 2, 2, 7, 4, 1, 5, 9, 6, 3, 7, 9};
    Pagina marco1, marco2, marco3;
    marco1.numero = marco2.numero = marco3.numero = 0;
    Pagina marcos[] = {marco1, marco2, marco3};
    int i = 0, j;
    int primero = 0, fallos = 0, hay = 0, k, tiempo_menor;
    printf("Tiempo:\tReferencia:\tMarco 1:\tMarco 2:\tMarco 3:\tFallos:\t\n");
    while (i < cantidad) {
        hay = 0;
        tiempo_menor = 25;
        for (j = 0; j < 3; ++j) {
            if (marcos[j].numero == 0) {
                marcos[j].numero = referencias[i];
                marcos[j].tiempo = i;
                ++fallos;
                hay = 1;
                break; 
            }
            if (referencias[i] == marcos[j].numero) {
                marcos[j].tiempo = i;
                break;
            }
            if (j == 2) {
                
                for (k = 0; k < 3; ++k) {
                    if (marcos[k].tiempo < tiempo_menor) {
                        tiempo_menor = marcos[k].tiempo;
                    }
                }
                for (k = 0; k < 3; ++k) {
                    if (marcos[k].tiempo == tiempo_menor) {
                        marcos[k].numero = referencias[i];
                        marcos[k].tiempo = i;
                        ++fallos;
                        hay = 1;
                        break;
                    }
                }
            }
        }


        Imprimir_es(referencias, marcos, hay, i);
        ++i; 
        
       
    }

    for (i = 0; i < 3; i++) {
        printf("%d\n", marcos[i].numero);
    }

}