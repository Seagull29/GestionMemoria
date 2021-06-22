#include <stdio.h>
#include <stdbool.h>

int page_found(int pno) { 
        int fno;
        for(fno = 0; fno < n; fno++)
            if (frames[fno].pno==pno)
                return fno;
        return -1;
}
int get_free_frame() {
    int fno;
    for (fno=0; fno <= n; fno++)
        if (frames[fno].pno==-1)
            return(fno);
    return(-1);
}
int get_mfu_frame() { 
    int fno; 
    int selfno = 0;
    for (fno = 1; fno < n; fno++)
        if (frames[fno].freq > frames[selfno].freq)
            selfno = fno;
    return selfno;
} 

void MFU() {
    int n; printf("\n\nALGORITMO MFU \n\n"); 
    mostrarPaginas();
    struct node {
        int pno,freq;
    }
    frames[20];
    
    int size = 25; 
    int catidad[25] = {2,3,2,1,5,2,4,5,3,2,5,2,8,6,2,2,7,4,1,5,9,6,3,7,9};
    int page_falts = 0,i,j,fno;
    n = 3;
    for (i=0; i<n; i++) {
        frames[i].pno = -1;
        frames[i].freq = 0;
    }

    printf("\t\tM1\tM2\tM3\tFallos");
    for(i = 0; i< size; i++) {
        j = page_found(catidad[i]);
        if (j==-1) {
            j = get_free_frame();
            if (j==-1)
                j = get_mfu_frame();
            page_falts++; 
            frames[j].pno = catidad[i];
            frames[j].freq = 1;
            printf("\nTiempo %d-> (%d)",i+1,catidad[i]);
            for (fno=0; fno<n; fno++) { 
                if(frames[fno].pno != -1)
                    printf("\t%4d",frames[fno].pno);
                else
                    printf("\t 0");

            }
            printf("\tFallo");
        } else {
            printf("\nTiempo %d-> (%d)",i+1,catidad[i]);
            frames[j].freq++;
            for (fno=0; fno<n; fno++) {
            ///----------------------------
                if(frames[fno].pno != -1)
                    printf("\t%4d", frames[fno].pno);
                else
                    printf("\t 0");
            ///----------------------------
            }
        }
    } 

    printf("\n\n");
    printf("\nTotal de fallas de pagina=%d",page_falts); 
    printf("\n\nTasa de fallas de pagina = %f \n\n\n\n", ((float)page_falts/(float)size));
    ArrayE[6] = page_falts;
    ArrayT[6] = ((float)page_falts/(float)size);
}