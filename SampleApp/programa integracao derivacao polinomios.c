#include <stdio.h>

int main()
{
    int grau;
    int quantCoeficientes;


    printf("Informe o maior grau\n");
    scanf("%d",&grau);

    quantCoeficientes = grau+1;

    printf("Informe os %d coeficientes\n",quantCoeficientes);

    int vetorCoeficientes[quantCoeficientes];

    for (int i=0; i<quantCoeficientes; i++)
    {
        scanf("%d",&vetorCoeficientes[i]);
    }

    int integral[quantCoeficientes+1];

    integral[0]=0;
    integral[1]=vetorCoeficientes[0];
    for (int i=2; i<(quantCoeficientes+1); i++){
           // printf("i+1 %d\n",i+1);
        //    printf("integral i %d\n",integral[i]);
            integral[i] = vetorCoeficientes[i-1]/(i) ;
    }

    printf("Integral :\n");

    for (int i=0; i<quantCoeficientes+1; i++){
            printf("%d ",integral[i]);
    }

    printf("\n\n");

    int derivada[quantCoeficientes];



    for (int i=0; i<(quantCoeficientes); i++){
            //printf("i+1 %d\n",i+1);
           // printf("integral i %d\n",integral[i]);
            derivada[i] = vetorCoeficientes[i+1]*(i+1);
    }

    printf("Derivada:\n");

    for (int i=0; i<quantCoeficientes-1; i++){
            printf("%d \n",derivada[i]);
    }

    //printf("%d ",5/2);





}

