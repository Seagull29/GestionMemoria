#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Comparacion (int n, int page[], int size) {
        int size2=size;
        int frames[n], use[n], fault, locat, found, i, j;
        bool var = false;
        ///----------------------------
        for(i=0; i<n; i++) { /* Initialize all array elements to 0
        */ frames[i]=0; use[i]=0;
        }
        fault=0;
        locat=0;
        printf("\t\tM1\tM2\tM3\tFallos\n");
        for(i=0; i<size; i++) { ///----------------------
   
            var = false;
            found=0; /* Reset */
            for(j = 0; j < n; j++) { /* Check if page is in memory */
                if (page[i]==frames[j]) {
                    found = 1;
                    use[j] = 1;
                }
            }   
            if (found == 0) {
                do { /* if bit is 0 or NULL, load in page */
                    if (use[locat] == 0) {
                        frames[locat] = page[i];
                        use[locat] = 1;
                        found = 1;
                        fault++;
                        var = true;
                    } else { /* reset use bit */
                        use[locat] = 0; 
                    }
                    locat++; /* Move pointer */
                    if(locat == n) { 
                        locat = 0; 
                    } /* Reset */
                } while (found != 1);
            }       
            printf("Tiempo %d-> (%d)",i+1,page[i]); 
            for (int h = 0 ; h < n; h++) {
                printf("\t %d ", frames[h]);
            }
            if  (var)
                printf("\tFallo");
            ///----------------------------
            printf("\n");
        }
        printf("\n\n");
        printf("Total de fallas de pagina: %d\n\n", fault);
        ArrayE[5] = fault;
        printf("Tasa Fallas: %f\n\n\n\n",((float)fault/(float)size2));
        ArrayT[5] = ((float) fault/(float)size2);
}

void Reloj() {
    printf("\n\n ALGORITMO RELOJ \n\n");
    mostrarPaginas(); 
    
    int frameNum,n,i=0;
    frameNum = 3;
    n = 25;
    int pages[25] = {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9};
    Comparacion(frameNum,pages,25); 
}