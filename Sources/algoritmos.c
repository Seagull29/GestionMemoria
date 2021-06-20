#include "Headers/algoritmos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Ejemplo() {
    printf("Ejemplo de uso\n");
}
void LRU() {
    char stack[5] = { 0 }; //Apilar
    char visit_pages[11] = { '3', '5', '0', '5', '1', '0', '8', '2', '5', '1', '3' }; // Pista de acceso

    // imprimir elementos de pila
    void print_stack(){
        int m;
        // imprimir elementos de pila
        for (m = 0; m < 5; m++) {
            if (stack[m] == NULL) {
                printf("  N");
            }
            else {
                printf("  %c", stack[m]);
            }
        }
        printf("\n\n");
    }

    // Mover el valor de la pila
    void change_stack(int index, int i)
    {
        int temp, k;
        // Después de guardar los elementos en la parte inferior de la pila, cúbralos por turnos
        temp = stack[index];
        for (k = index; k < 5; k++) { // Después de valores de subíndice iguales, sobrescribir
            if (index != 0) {// Solo cuando la pila no está llena, puedes saltar directamente del bucle
                if (stack[k + 1] == NULL) {
                    break;
                }
            }
            if (k + 1 < 5) {
                stack[k] = stack[k + 1];
            }
        }
        // Dos situaciones diferentes usan asignaciones diferentes
        if (index != 0) {
            stack[k] = temp; // Burbujeando hasta la cima
            stack[k] = visit_pages[i]; // Reemplazar el valor superior
        }
        else {
            stack[4] = temp; // Burbujeando hasta la cima
            stack[4] = visit_pages[i]; // Reemplazar el valor superior
        }
    }

    int main()
    {
        int i, j, k;
        int index; //Subíndice
        int temp; // Valor del volumen medio

        // Asignación de pila
        for (i = 0; i < 5; i++) {
            stack[i] = NULL;
        }

        printf("Parte inferior de la pila-> Parte superior de la pila: \ n");
        print_stack(); // Impresión de pila inicial
        for (i = 0; i < strlen(visit_pages); i++) {
            for (j = 0; j < 5; j++) {
                if (stack[j] == NULL) {
                    stack[j] = visit_pages[i];
                    break;
                }
                if (stack[j] == visit_pages[i]) {// Hay elementos de acceso en la pila
                    if (j + 1 < 5 && stack[j + 1] == NULL || j == 4) { // El elemento al que se accede es el elemento superior, y el elemento superior es NULL, o, el elemento al que se accede es el elemento superior de la pila, y salta del bucle
                        break;
                    }
                    change_stack(j, i); // Mover el valor de la pila
                }
                else if (j == 4 && stack[j] != visit_pages[i]) {// No hay elementos de acceso en la pila
                    change_stack(0, i); // Mover el valor de la pila
                }
            }
            printf("---> %c:\n", visit_pages[i]);
            print_stack();
        }

        return 0;
    }
}
    void reloj() {
#define length 10// Define la longitud de la matriz

    typedef struct Node {// Generar nodo de datos
        int index;
        int list;
        int A;// Logotipo de acceso
        int M;// Modificar la bandera
    } dataNode;

    dataNode* initList(dataNode node[]) {// Generar secuencia de acceso aleatorio
        for (int i = 0; i < length; ++i) {
            int randNumber = rand() % 9 + 1;
            int randNumber2 = rand() % 2;
            int randNumber3 = rand() % 2;
            node[i].index = i;
            node[i].list = randNumber;
            node[i].A = randNumber2;
            node[i].M = randNumber3;
        }
        return node;
    }

    void NRU(dataNode node[], int bwoList[]) {// El núcleo del algoritmo de eliminación no se ha utilizado por más tiempo recientemente

        int count = 0;// Establecer todo 0 cuando las condiciones de lanzamiento
        int index = 1;
        while (count <= length) {
            int countLoss = 0;// Cuente el número de páginas que faltan
            int cou = 0;// Secuencia de eliminación de almacenamiento
            printf("La secuencia de eliminación% d es:", index++);
            for (int i = 0; i < length; ++i) {
                if (node[i].A == 0) {
                    if (node[i].M == 0) {
                        countLoss++;
                        count++;
                        printf("%d ", node[i].list);
                        bwoList[i - cou] = node[i].list;
                    }
                    else {
                        node[i].M = 0;
                    }
                }
                else {
                    node[i].A = 0;
                }
            }
            printf("\n");
            printf("---- La tasa de eliminación:% .2lf %% \ n", (1.0 * countLoss / length) * 100);
        }

    }


    int main() {
        printf("\ tBienvenido al algoritmo de eliminación de reloj simple \ n");
        int bwoList[length];// Eliminar secuencia
        memset(bwoList, -1, sizeof(bwoList));
        dataNode node[length];// Generar estructura de acceso al reloj
        initList(node);
        printf("---- Datos relacionados generados aleatoriamente: \ n");
        for (int j = 0; j < length; ++j) {
            if (j < length - 1)
                printf("%d %d %d %d", node[j].index, node[j].list, node[j].A, node[j].M);
            else
                printf("%d %d %d %d", node[j].index, node[j].list, node[j].A, node[j].M);
            printf("\n");

        }
        NRU(node, bwoList);

    }

    }
