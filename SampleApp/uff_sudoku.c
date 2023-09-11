#include <stdio.h>
#include <stdlib.h>

int validarSudoku(int sudoku[9][9])
{
    int i=0;
    int j=0;

    for (i=0; i< 9; i++)
    {
        for (j=0; j<8; j++)
        {
            printf("%d ",sudoku[i][j]);
            if (sudoku[i][j] == sudoku[i][j+1]) return 0;
        }
        printf("\n");
    }

    for (i=0; i< 8; i++)
    {
        for (j=0; j<9; j++)
        {
            if (sudoku[i][j] == sudoku[i+1][j]) return 0;
        }
    }

    int quadrado[9][9]= {0};
    int posicaoQuadrado;

    for (i=0; i< 9; i++)
    {
        for (j=0; j<9; j++)
        {
            if (i<=2 && j<=2){
                posicaoQuadrado = 0;
                printf("%d ",sudoku[i][j]);
                quadrado[0][posicaoQuadrado] = sudoku[i][j];
               posicaoQuadrado++;
            }

//             if (i>=3 && i<=5 && j>=3 && j<=5 ){
//                posicaoQuadrado = 0;
//                printf("%d ",sudoku[i][j]);
//                quadrado[1][posicaoQuadrado] = sudoku[i][j];
//               posicaoQuadrado++;
//            }
//             if (i>5 && j>5){
//                posicaoQuadrado = 0;
//                printf("%d ",sudoku[i][j]);
//                quadrado[2][posicaoQuadrado] = sudoku[i][j];
//               posicaoQuadrado++;
//            }



        }

    }

   // for (i=0;i>9;i++){
    //    printf("%d ",quadrado[i]);
   // }
    printf("\n");
    return 1;
}

    int main()
    {
        int resultado;


        int sudoku[9][9]=   {5,3,4,  6,7,8,  9,1,2,
                             6,7,2,  1,9,5,  3,4,8,
                             1,9,8,  3,4,2,  5,6,5,
                             8,5,9,  7,6,1,  4,2,3,
                             4,2,6,  8,5,3,  7,9,1,
                             7,1,3,  9,2,4,  8,5,6,
                             9,6,1,  5,3,7,  2,8,4,
                             2,8,7,  4,1,9,  6,3,5,
                             3,4,5,  2,8,6,  1,7,9
                            };



        resultado = validarSudoku(sudoku);
        printf("%d \n",resultado);







    }
