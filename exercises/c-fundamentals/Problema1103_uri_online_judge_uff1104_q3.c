#include <stdio.h>

/*
Q2) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a
resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa
para quando n for menor ou igual a zero.*/

int main (void)
{
    int H1, M1,H2,M2,quant_min1, quant_min2;

    while(1)
    {
        printf("Digite a hora corrente e a hora do alarme\n");
        scanf("%d %d %d %d",&H1,&M1,&H2,&M2);

        if ((H1<0 || H1>23) || (M1<0 || M1>59) || (H2<0 || H2>23) ||( M2 < 0 || M2>59))
        {
            printf("Valores inseridos incorretos\n");
            continue;
        }
        else
            quant_min1 = (H2*60+M2)-(H1*60+M1);
        {
            if (quant_min1 > 0 )
            {
                printf("%d\n",quant_min1);

            }

            else
            {
                if (quant_min1 < 0)
                {
                    quant_min1 += 1440;
                    printf("%d\n",quant_min1);
                }
                else
                {
                    if(H1==0 && M1 ==0 && H2 == 0 && M2 == 0) printf("%c \n",'\0');

                }
            }
        }

    }
    return 0;

}






