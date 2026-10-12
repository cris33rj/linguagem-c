#include <stdio.h>

int main(void)
{
    printf("Informe quantos numero na sequencia");
    int quantNumeros = 4;

    // scanf("%d", &quantNumeros);

    int a[quantNumeros];
    int i = 0;

    a[0] = 1;
    a[1] = 1;

    for (i = 2; i < quantNumeros; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        // printf("%d",a[i]);
    }
    printf("imprimindo tudo\n");

    for (i = 0; i < quantNumeros; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    printf("%d", a[quantNumeros - 1]);
}
