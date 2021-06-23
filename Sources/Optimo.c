#include <stdio.h>
#include <stdlib.h>

void Optimo() {
    printf("\n\n ALGORITMO OPTIMO \n\n"); 
    int marcos, referencias, frames[10], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0; 

    // Variables estaticas 
    marcos = 3; referencias = 25; 
    int pages[30] = {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9};
    for (i = 0; i < marcos; ++i) {
        frames[i] = 0;
    }
    printf("\t\t M1\tM2\tM3\tFallos\n");
    for (i = 0; i < referencias; ++i) {
        flag1 = flag2 = 0;
        for (j = 0; j < marcos; ++j) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
            }
        }
        if (flag1 == 0) { 
            for (j = 0; j < marcos; ++j) { 
                if (frames[j] == 0) {
                    faults++; frames[j] =
                    pages[i]; flag2 = 1;
                }
            }
        }
        if (flag2 == 0) {
            flag3 = 0; 
        
            for (j = 0; j < marcos; ++j) {
                temp[j] = -1;
                for (k = i + 1; k < referencias; ++k) {
                    if (frames[j] == pages[k]) {
                        temp[j] = k;
                    }
                }
            }
            for (j = 0; j < marcos; ++j) {
                if (temp[j] == -1) { 
                    pos = j; 
                    flag3 = 1;
                }
            }
            if (flag3 == 0) {
                max = temp[0];
                pos = 0;
                for (j = 1; j < marcos; ++j) {
                    if (temp[j] > max) { 
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        } 
    
        /* Imprimir */ 
        printf("Tiempo %d-> (%d)\t:", i+1, pages[i]); 
        for (j = 0; j < marcos; ++j)
            printf("%d\t", frames[j]);
        // Si hay fallo 
        if (flag2 == 0 || flag1 == 0) 
            printf("Fallo"); 
        printf("\n");
    } 
    printf("\n\nTotal de fallas de pagina = %d \n", faults); 
    printf("\nTasa de fallas de pagina = %f \n\n\n\n", ((float) faults / (float) referencias));

    //ArrayE[2] = faults;
    //ArrayT[2] = ((float) faults / (float) referencias); 
}