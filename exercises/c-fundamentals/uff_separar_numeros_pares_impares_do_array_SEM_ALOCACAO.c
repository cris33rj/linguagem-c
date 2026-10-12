#include <stdio.h>


void transf_i_p (int *vet1, int n)
{

    int i,j=0,k=0;
    int vet2[10];
    int vet3[10];

    for(i=0; i<n; i++)
    {
        if (vet1[i]%2==0)
        {
           // printf("entrou");
            vet2[j] = vet1[i];
            j++;
        }
        else
        {
            vet3[k] = vet1[i];
            k++;
        }
    }

    printf("\nThe Even elements are : \n");
    for(i=0; i<j; i++)
    {
        printf("%d ",vet2[i]);
    }

    printf("\nThe Odd elements are :\n");
    for(i=0; i<k; i++)
    {
        printf("%d ", vet3[i]);
    }
    printf("\n\n");

}

void main()
{
    int vet1[10];
    int i,j=0,k=0,n;


    printf("\n\nSeparate odd and even integers in separate arrays:\n");
    printf("------------------------------------------------------\n");

    printf("Input the number of elements to be stored in the array :");
    scanf("%d",&n);

    printf("Input %d elements in the array :\n",n);
    for(i=0; i<n; i++)
    {
        printf("element - %d : ",i);
        scanf("%d",&vet1[i]);
    }

    transf_i_p(vet1,n);
}
