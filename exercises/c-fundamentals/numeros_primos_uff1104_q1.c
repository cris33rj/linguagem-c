#include <stdio.h>

int main (void)
{
    int i;
    int n;
    int num  = 2;
    printf("Informe o numero: ");
    scanf("%d", &n);
    printf("Lista dos %d primeiros numeros primos existentes:\n",n);


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
}






