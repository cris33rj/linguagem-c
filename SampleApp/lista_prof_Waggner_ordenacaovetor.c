#include <stdio.h>
#include <stdlib.h>

int main()
{
    int soma=0;

    int i;
    int matriz [5][7] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
    int matriz_soma [5][7] = {0};

//    for (int i=0; i<5; i++)
//    {
//        for (int j=0; j<7; j++)
//        {
//             soma = soma + matriz[i][j];
//
//        }
//    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            soma += matriz[i][j]; // acumula a soma
            printf("%2d ", matriz[i][j]); // imprime a matriz
        }
        printf("\n");
    }

    // imprime a soma dos elementos da matriz
    printf("\n\nSoma total: %d\n\n", soma);



    printf("soma total %d: ",soma);
}



