#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, valorInicial = 1, valorFinal = 0;

    for(i = 1; i <= 30; i++){
        valorInicial = valorInicial * 2;
        //printf("valorInicial %d\n",valorInicial);
        //break;
        //valorFinal += valorInicial;
    }

    printf("Valor em centavos: %d\n", valorInicial-1);
    printf("R$%.2f\n\n", (valorInicial-1) / 100.0);
}
