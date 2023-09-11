#include <stdio.h>

/*
Q2) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a
resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa
para quando n for menor ou igual a zero.*/

int main (void)
{
    int i;
    int n;
    int num  = 2;

    do{
    printf("Informe o numero n\n");
    scanf("%d", &n);
    printf("Lista dos numeros primos existentes depois de %d\n",n);


    while(n)
    {

        for (i=2; i<num; i++)
        {
           // printf("dividindo %d por %d\n",num,i);
            if (num%i==0)
                break;
        }
        if(num==i)
        {
            printf("%d\n",num);
            n--;
        }

        num++;

    }

    }while(n>=0);
}






