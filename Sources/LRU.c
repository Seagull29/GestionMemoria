#include <stdlib.h>
#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }   
    }
    return minimum[0];
} 


void LRU() {
    printf("\n\n ALGORITMO LRU \n\n"); 
    mostrarPaginas(); 
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
    ArrayE[0] = faults;
    ArrayT[0] = tasa;
    printf("\n\nTotal de fallas de pagina = %d", faults);
    printf("\n\nTasa de fallas de pagina = %f \n\n\n\n", tasa);
}