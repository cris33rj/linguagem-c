#include<stdio.h>

int main()
{
    int i, j,total_count, count,n;

    do {
        total_count = 1;
        count = 1;
        printf("Informe n:\n");
        scanf("%d",&n);

        int sequencia[n];

        printf("Informe o valores\n");
        for(i=0;i<n;i++){
            scanf("%d",&sequencia[i]);
        }
        //int sequencia[] = {5,10,3,2,4,7,8,9,5};
//int sequencia[] = {10,8,7,5,2};
        for(i=0; i<n; i++)
        {
            printf("imprimindo sequencia i: %d",sequencia[i]);
            printf("imprimindo sequencia i+1: %d",sequencia[i-1]);
            if (sequencia[i]>sequencia[i-1]){
                    printf("imprimindo count: %d",count);
                count++;
            }
            else
            {
                if (count > total_count)
                {

                    total_count = count;
                }
                    count=1;

            }

        }
        if (count > total_count)
                {

                    total_count = count;

                }

        printf("Imprimindo comprimento maximo %d\n",total_count);
    } while(n>0);
}


