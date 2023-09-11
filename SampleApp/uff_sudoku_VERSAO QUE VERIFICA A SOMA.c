#include <stdio.h>
#include <stdlib.h>

int validarSudoku(int sudoku[9][9])
{
    int i=0;
    int j=0;
    int somaLinha = 0;
    int somaColuna = 0;
    int somaBox1 = 0;

    for (i=0; i<9; i++)
    {
        for (j=0; j<9; j++)
        {
            somaLinha+= sudoku[i][j];

        }
        if (somaLinha!=45) return 0;
        somaLinha = 0;
    }

    for (i=0; i< 9; i++)
    {
        for (j=0; j<9; j++)
        {
            somaColuna+= sudoku[j][i];
        }
        if (somaColuna!=45) return 0;
        somaColuna = 0;
    }

     for (i=0; i< 3; i++)
    {
        for (j=0; j<3; j++)
        {
            somaColuna+= sudoku[][i];
        }
        if (somaColuna!=45) return 0;
        somaColuna = 0;
    }


    return 1;
}

    int main()
    {
        int resultado;


        int sudoku[9][9]=   {5,3,4,  6,7,8,  9,1,2,
                             6,7,2,  1,9,5,  3,4,8,
                             1,9,8,  3,4,2,  5,6,7,
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
