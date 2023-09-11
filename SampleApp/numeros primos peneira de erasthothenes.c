#include <stdio.h>



int main()
{   int n;

    printf("Informe n:");
    scanf("%d",&n);
    int numeros[n];

    for (int i=0; i<n-1; i++){
        numeros[i]=i+2;

    }

    //int numeros[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
    //int numeroscortados[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
    //int tam = 36;

    for(int i=0; i<n-1; i++)
    {
       // printf("imprimindo numero[i]%d\n ",numeros[i]);



        for (int j=1; j<n-1; j++){
            //    printf("imprimindo numero[j]%d\n ",numeros[j]);

            if (numeros[i]!=0 && numeros[j]!=0 && (numeros[j]!=numeros[i]) && (numeros[j]%numeros[i]==0)){
                numeros[j]=0;
            //    printf("imprimindo numero[j]%d-%d ",j,numeros[j]);
            }
        }

    }
     printf("\n");


    for(int g=0; g<n-1 ; g++)
    {
        if(numeros[g]!=0)
        printf("%d ",numeros[g]);
    }
return 0;


}
