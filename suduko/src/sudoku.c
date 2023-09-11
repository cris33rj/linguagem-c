#include "sudoku.h"

int main()
{
    int ** puzzle = createPuzzle();
    Square *** sudoku;

    printPuzzle(puzzle);

    sudoku = setUpPuzzle(puzzle);

    return 0;
}
