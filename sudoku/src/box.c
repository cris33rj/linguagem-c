#include "sudoku.h"

Box ** createBoxes()
{
    int x, y;
    Box ** boxes;
    boxes = malloc(sizeof(Box*)*9);

    for (x=0; x<9; x++)
    {
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9);
        boxes[x]->numbers =0;
        boxes[x]->solvable=9;

        for (y=0;y<9;y++)
            boxes[x]->possible[y] = 0;
    }

    return 1;


}
