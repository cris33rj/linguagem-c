#include <stdio.h>
#include <stdlib.h>

int main() {
    int segundos=0;
    float massaInicial;
    float massaFinal = 0.05;

    printf("Informe a massa inicial");
    scanf("%f",&massaInicial);


    printf("massa inicial %f :\n ",massaInicial);
    printf("massa final %f : \n",massaFinal);
    while(massaInicial >= massaFinal){
        segundos++;
        if (segundos%50==0){
            massaInicial/=2;
            //printf("MassaInicial %d",massaInicial);
        }

    }

    printf("Tempo total %d: ",segundos);
    printf("Massa final %f: ",massaInicial);
}
