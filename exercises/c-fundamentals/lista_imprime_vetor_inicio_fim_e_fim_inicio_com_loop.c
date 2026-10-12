#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int num[10];
    int op = 0;

    do{

    for(i = 0; i < 10; i++){ // preenche o vetor lendo do teclado
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &num[i]);
    }

    printf("Escolha uma opcao\n");
    scanf("%d",&op);
    //printf("imprimindo opcao %d",op);

    switch(op){
    case 0: printf("Finalizando programa...\n"); break;
    case 1: for(i = 0; i < 10; i++){ // preenche o vetor lendo do teclado
            printf("%d ", num[i]);
            }
            printf("\n");
            break;
    case 2: for(i = 9; i>=0; i--){ // preenche o vetor lendo do teclado
            printf("%d ", num[i]);}
            printf("\n");
            break;


    default : printf("Opcao invalida\n");

    }
    }while(op!=0);

}
