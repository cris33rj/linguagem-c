#include<stdio.h>
#include<string.h>

int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2)
{
    int i,j,k;

//     for(i=0;i<3;i++){
//            printf("\n");
//        for (j=0;j<2;j++){
//            printf("% d",mat1[i][j]);
//        }
//    }

    printf("\n");

//    for(i=0;i<2;i++){
//        printf("\n");
//        for (j=0;j<2;j++){
//            printf("% d",mat2[i][j]);
//        }
//    }



    int ** multi =(int**) malloc(sizeof(int **)*3);

    for (i=0; i<3; i++)
    {

        multi[i] = (int *) malloc(sizeof(int *)*2);
    }

     for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            multi[i][j]=0;
            for(k=0; k<2; k++)
            {
                multi[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }

//printf("xx---");
//
//    for(i=0; i<2; i++)
//        {
//        for (j=0; j<2; j++)
//        {
//            printf("XX---");
//        }
//    }



    return multi;

}


int main()
{
    srand(time(NULL));
    int i,j;

    int ** mat1 =(int**) malloc(sizeof(int **)*3);

    for (i=0; i<3; i++)
    {

        mat1[i] = (int *) malloc(sizeof(int *)*2);
    }

    for(i=0; i<3; i++)
    {
        for (j=0; j<2; j++)
        {
            mat1[i][j] = rand()%10;
        }
    }

//    for(i=0;i<3;i++){
//        for (j=0;j<2;j++){
//            printf("%d ",mat1[i][j]);
//        }
//    }

    printf("\n");

    int ** mat2 =(int**) malloc(sizeof(int **)*2);

    for (i=0; i<2; i++)
    {

        mat2[i] = (int *) malloc(sizeof(int *)*2);
    }

    for(i=0; i<2; i++)
    {
        for (j=0; j<2; j++)
        {
            mat2[i][j] = rand()%10;
        }
    }

//    for(i=0;i<2;i++){
//        for (j=0;j<2;j++){
//            printf("%d ",mat2[i][j]);
//        }
//    }



    int ** resultado = mult(3,2,mat1,2,2,mat2);

    for(i=0; i<3; i++)
    { printf("\n");
        for (j=0; j<2; j++)
        {
            printf("%d ",resultado[i][j]);
        }
    }






}
