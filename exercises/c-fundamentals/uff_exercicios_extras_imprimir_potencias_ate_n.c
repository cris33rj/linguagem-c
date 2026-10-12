#include<stdio.h>

int main ()
{
    int m, n, i, num;
    do
    {
        n=0;
        m=0;
        num=0,i=0;
        printf("\n");
        printf("Inform n:\n");
        scanf("%d",&n);
        // printf("passou por aqui1");
        printf("Inform m:\n");
        scanf("%d",&m);
        printf("\n");

        if (n>1 && m!=0 && m!=1 && m!=-1)
        {

            while(num<n)
            {
                num = (pow(m,i));
                if (num < n)
                    printf("%d ",num);
                i++;
            }

            printf("\n");
        }

    }
    while (n>1 && m!=0 && m!=1 && m!=-1);
}
