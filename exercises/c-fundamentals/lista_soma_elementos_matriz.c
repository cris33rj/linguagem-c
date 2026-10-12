#include <stdio.h>
#include <stdlib.h>

int ordenarVetor(int *vetor){
    int temp = 0;

    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if (vetor[i] < vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    for (int i=0; i<10; i++){
        printf("%d\n",vetor[i]);

    }
}

int main() {

    int i;
    int num[10];
    int op = 0;



    for(i = 0; i < 10; i++){ // preenche o vetor lendo do teclado
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &num[i]);
    }

    ordenarVetor(num);

}
