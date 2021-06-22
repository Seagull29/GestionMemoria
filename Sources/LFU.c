#include <stdio.h>
#include <stdbool.h>


void LFU() {
    int i, mPos, hayFallo, memLlena, valorNodoLFU; 
    int nroMarcos = 3; int nroRefs = 25; // Nro de referencias 
    int refs[25] = {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9}; 
    struct nodo* hashMap = (struct nodo*) malloc (sizeof(struct nodo)); 
    struct nodo* contador = (struct nodo*) malloc (sizeof(struct nodo)); 
    struct nodo* nodoLFU = (struct nodo*) malloc (sizeof(struct nodo)); 
    int memoria[3];
    hashMap->valor = refs[0]; hashMap->conteo = 0;
    /* Inicializamos la memoria con la cantidad de marcos */ struct marco*
    ptrMemoria = (struct marco*) malloc (sizeof(struct marco)); struct marco*
    inicioMemoria = (struct marco*) malloc (sizeof(struct marco)); ptrMemoria =
    inicioMemoria = (struct marco*) malloc (sizeof(struct marco));
    inicioMemoria->valor = 0; 
    inicioMemoria->siguiente = NULL;
    for (i = 0; i < nroMarcos - 1; ++i) {
        struct marco* nuevoMarco = (struct marco*) malloc (sizeof(struct marco));
        nuevoMarco->valor = 0; 
        ptrMemoria->siguiente = nuevoMarco;
        ptrMemoria = nuevoMarco;
    }
    ptrMemoria->siguiente = NULL; 

    printf("\t\t M1\tM2\tM3\tFallos\n");
    /* Para cada referencia */
    for (i = 0; i < nroRefs; ++i){
    /* Conteo de frecuencia */
    // Si se encuentra la ref en el HashMap se incrementa 
        if ((contador = buscar(refs[i], hashMap)) != NULL) { 
            contador->valor++;
        // Si no, se agrega un nuevo nodo
        } else 
            ultimoNodo(hashMap)->siguiente = nuevoNodo(i);
        /* Busqueda en la memoria */ hayFallo = 1; marco*
        marcoActual = (struct marco*) malloc (sizeof(struct marco));
        marcoActual = inicioMemoria; 
        mPos = 0; 
        if (nroMarcos == 1) {
            if(marcoActual->valor == refs[i]){ 
                buscar(marcoActual->valor, hashMap)->conteo ++; 
                hayFallo = 0; 
                break;
            }
        } else {
            while(marcoActual != NULL){
                if (marcoActual->valor == refs[i]) {
                    buscar(marcoActual->valor, hashMap)->conteo ++;
                    hayFallo = 0; 
                    break;
                }
                marcoActual = marcoActual->siguiente;
                mPos++;
            }
        }

        if (hayFallo){
            memLlena = 1; 
            /* Si hay fallo y memoria vacia */
            marcoActual = inicioMemoria;
            while(marcoActual != NULL) {
                if (marcoActual->valor == 0){
                    marcoActual->valor = refs[i];
                    memLlena = 0; 
                    break;
                }
                marcoActual = marcoActual->siguiente;
            }
        /* Si hay fallo y memoria llena */ 
            marcoActual = inicioMemoria; 
            if (memLlena) { 
                nodoLFU = nodoMenosUsado(hashMap, inicioMemoria); 
                nodoLFU->conteo = 0;
                marcoActual = buscarEnMem(nodoLFU->valor, inicioMemoria);
                marcoActual->valor = refs[i];
            }
        } else {
            marcoActual->valor = refs[i];
        }
        /* Impresión */
        printf("Tiempo %d-> (%d)\t:", i+1, refs[i]);
        marcoActual = inicioMemoria;
        while (marcoActual != NULL){
            printf("%d\t", marcoActual->valor);
            marcoActual = marcoActual->siguiente;
        } 
        if (hayFallo) 
            printf("Fallo");
        printf("\n"); 
    } 
}