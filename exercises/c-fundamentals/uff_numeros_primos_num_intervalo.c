#include <stdio.h>
#include <stdlib.h>

/*
              Código escrito por Wagner Gaspar
              em 23/05/2022
*/

int ehPrimo(int x)
{
    int i, divisores = 0;

    for(i = 1; i <= x; i++)
    {
        if(x % i == 0)
            divisores++;
    }

    if(divisores == 2)
        return 1;// é primo
    else
        return 0; // não é primo
}

int main()
{
    int i;

    for(i = 4; i <= 20; i++)
    {
        if(ehPrimo(i) == 1) // se for primo
            printf("%d, ", i); // imprime na tela
    }
    return 0;
}
