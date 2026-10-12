#include "stdio.h"

void bublesort(int vetor[], int tamanho) {
    int aux = 0;

   for (int j=0; j< tamanho; j++){
        for (int i=0; i < tamanho-1;i++){
            if (vetor[i] > vetor[i+1]){
                    aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1] = aux;
            }
        }

   }

}

/*
int imprimir(int *vetor,int tamanho){
for (int i=0; i<tamanho;i++){
    printf("%d", *(vetor+i));
   }
}
*/

int imprimir(int vetor[],int tamanho){
for (int i=0; i<tamanho;i++){
    printf("%d", *(vetor+i));
   }
}


int main()
{
    int vetor[10] = {5,8,7,4,0,2,6,1,3,9};
    bublesort(vetor,10);
    imprimir(vetor,10);

    return 0;
}
