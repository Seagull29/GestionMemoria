#include <stdio.h>
#include <stdbool.h>

void Aleatorio() {
    printf("\n\n ALGORITMO ALEATORIO \n\n");
    mostrarPaginas();
    bool verificar(int n,int marcos[])
    {
    int k;
    bool ver = true;
    //printf("%d / %d\n",n,marcos[1]);
    for(k=0;k<3;k++)
    {
    if(marcos[k]==n)
    {
    ver = false;
    }
    }
    return ver;
    } int
    random() {
    int r;
    r = rand()%3;
    return r;
    }
    void imprimir(int marcos[],int n,int T, int aux[])
    { 
    20
    bool var =true;
    printf("Tiempo %d-> (%d)",T,n);
    int k;
    for(k=0;k<3;k++)
    {
    printf("\t %d",marcos[k]);
    }
    for(k=0;k<3;k++)
    {
    if(marcos[k]!=aux[k])
    var=false;
    }
    if(!var)
    {
    C++;
    printf("\tFallo");
    }
    printf("\n");
    }
    int pages[25] =
    {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9}; int
    marcos[3]={0,0,0}; int aux[3]; int paginas = 25;
    int i;
    float c=0;
    printf("\n\t\tM1\tM2\tM3\tFallos\n");
    for(i=0;i<25;i++)
    {
    aux[0] = marcos[0];
    aux[1] = marcos[1]; aux[2]
    = marcos[2];
    if(!verificar(pages[i],marcos)) 
    21
    {
    int r = random();
    int k,j=0; for(k=0;k<3;k++){
    if(marcos[k]==0 &&
    j==0)
    {
    marcos[k]=pages[i];
    j=1;
    }
    }
    if(i>3)
    {
    marcos[r]=pages[i];
    }
    }
    imprimir(marcos,pages[i],i,aux);
    }
    float a=C/25;
    printf("\nTotal de fallas de pagina: %d\n", (int)C);
    printf("\nTasa Fallas: %f\n\n\n\n",a);
    ArrayE[7]=(int)C;
    ArrayT[7]=a;
    C=0; 
}