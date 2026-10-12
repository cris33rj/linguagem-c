#include<stdio.h>
#include<stdlib.h>

int i, j, k;
k=0;
i=0;
j=0;

int* junta(int *vet1, int n1, int *vet2,int n2)
{
    int length = n1+n2;

    int * junta_ordenado = (int *) malloc(sizeof(int)*length);

    while (i<n1 && j<n2)
    {
        if (vet1[i]<vet2[j])
        {
            junta_ordenado[k]=vet1[i];
            k++;
            i++;
        }
        else
        {
            junta_ordenado[k]=vet2[j];
            k++;
            j++;
        }

    }

    while (i<n1)
    {
        junta_ordenado[k]=vet1[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        junta_ordenado[k]=vet2[j];
        j++;
        k++;
    }

    return junta_ordenado;
}

int main()
{

    int n1 = 4;
    int n2 = 3;

    int vet1[] = {1,2,5,8};
    int vet2[] = {0,6,9};

    int * junta_ordena = junta(vet1,n1, vet2, n2);

    for (i=0; i<7; i++)
    {
        printf("%d ",junta_ordena[i]);
    }


}

