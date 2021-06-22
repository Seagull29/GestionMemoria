#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void LIFO() {
    printf("\n\nALGORITMO LIFO\n\n"); 
    mostrarPaginas(); 
    int marcos,referencias;
    marcos = 3; referencias = 25; int cantidad[25] = {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9};
    int auxi[marcos][referencias];
    int errores = 0; 
    for (int i = 0; i < marcos; i++) { 
        for (int j = 0; j < referencias; j++) {
            auxi[i][j] = 0;
        }
    }
    for (int referencias2 = 0; referencias2 < referencias; referencias2++) {
        int uso = 0; 
        int vacio = -1;
        if (referencias2 != 0) {
            for (int i = 0;i < marcos; i++) {
                auxi[i][referencias2] = auxi[i][referencias2 -1];
            }
            for (int i=0;i<marcos;i++) {
                if (auxi[i][referencias2] == cantidad[referencias2]) 
                    uso++;
            }
            if (uso == 0) {
                errores++;
                for (int i = 0; i < marcos; i++) {
                    if (auxi[i][referencias2] == 0 && vacio == -1)
                        vacio = i;
                }
                if (vacio == -1) {
                    int numeros[marcos-1]; 
                    for (int p = 0; p < marcos; p++) {
                        numeros[p]=auxi[p][referencias2];
                    }
                    //for (int p = 0; p < marcos; p++){}
                    
                    for (int p = referencias2 ;vacio ==-1; p--) {
                        for (int p2 = 0; p2 < marcos; p2++) {
                            if (auxi[p2][p] != numeros[p2] && vacio ==-1)
                                vacio=p2;
                        }
                    }
                }
                auxi[vacio][referencias2] = cantidad[referencias2];
            }
        } else {
            errores++;
            auxi[0][0]=cantidad[0];
        }
    } 
    
    printf("\t\tMI\tM2\tM3\tFALLOS\n"); 
    for(int j = 0 ; j < referencias; j++) { 
        printf("Tiempo %d-> (%d)", j + 1, cantidad[j]); 
        for (int i = 0 ; i < marcos; i++) {
            printf("\t %i ",auxi[i][j]);
        }
        int k;
        if (j != 0 ) {
            for ( k = 0; k < 3; k++) {
                if (auxi[k][j] != auxi[k][j-1]) {
                    printf("\t Fallo");
                }
            }
        } else
            printf("\t Fallo");
        printf("\n");
    }
    printf("\nTotal de fallas de pagina: %i \n",errores); 
    ArrayE[4] = errores;
    printf("\nTasa de fallas de página = %f\n\n\n\n", (float)errores/referencias); 
    ArrayT[4] = (float)errores/referencias; 
}