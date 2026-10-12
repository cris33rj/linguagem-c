#include <stdio.h>

int main(void)
{


    int quantSuspeitos = 0;


    while(scanf("%d",&quantSuspeitos) &&  quantSuspeitos != 0 )
    {

        int valoresSuspeitos[quantSuspeitos];


        for (int i=0; i<quantSuspeitos; i++)
        {
            scanf("%d",&valoresSuspeitos[i]);
        }


        int valoresSuspeitosOriginal[quantSuspeitos];


        for (int i=0; i<quantSuspeitos; i++)
        {
            valoresSuspeitosOriginal[i] = valoresSuspeitos[i];
        }




        int temp = 0;
        for (int i=0; i<quantSuspeitos; i++)
        {
            for (int j=0; j<quantSuspeitos-1; j++)
            {
                if (valoresSuspeitos[j+1] > valoresSuspeitos[j])
                {
                    temp = valoresSuspeitos[j+1];
                    valoresSuspeitos[j+1] = valoresSuspeitos[j];
                    valoresSuspeitos[j]=temp;
                }

            }
        }

        int valorAssassino = valoresSuspeitos[1];



        for (int i=0; i<quantSuspeitos; i++)
        {
            if (valoresSuspeitosOriginal[i]==valorAssassino)
            {
                printf("%d\n",i+1);
                break;
            }
        }
    }

    return 0;

}
