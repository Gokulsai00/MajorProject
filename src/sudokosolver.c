#include <stdio.h>

/* 
sudoko is a 9x9
*/
#define SIZE 9  

/*
    Prints the Sudoku board.
*/
void showBoard(int a[SIZE][SIZE])
{
    int r, c;
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            printf("%d ", a[r][c]);
        }
        printf("\n");
    }
}

/*
    Check if 'num' can be placed at (row, col).
*/
int allowed(int a[SIZE][SIZE], int row, int col, int num)
{
    int i, j;

    /* Check the row */
    for (i = 0; i < SIZE; i++) {
        if (a[row][i] == num)
            return 0;
    }

    /* Check the column */
    for (i = 0; i < SIZE; i++) {
        if (a[i][col] == num)
            return 0;
    }

    /* Check the 3x3 block */
    int rstart = row - (row % 3);
    int cstart = col - (col % 3);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[rstart + i][cstart + j] == num)
                return 0;
        }
    }

    return 1;
}

int fillSudoku(int a[SIZE][SIZE])
{
    int r, c;
    int foundEmpty = 0;

    /* Find an empty slot */
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            if (a[r][c] == 0) {
                foundEmpty = 1;
                goto leave_loop;   
            }
        }
    }

leave_loop:

    /* If no empty space was found, puzzle is solved */
    if (!foundEmpty)
        return 1;

    /* Try digits 1 to 9 */
    for (int num = 1; num <= 9; num++) {

        if (allowed(a, r, c, num)) {
            a[r][c] = num;

            if (fillSudoku(a))
                return 1;

            a[r][c] = 0;  /* undo */
        }
    }

    return 0;  /* applies backtracking */
}

int main()
{
    int grid[SIZE][SIZE];
    int i, j;

    printf("Enter the Sudoku grid (0 for empty cells):\n");

    /* Input values */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (fillSudoku(grid)) {
        printf("\nSolved Sudoku:\n");
        showBoard(grid);
    } else {
        printf("\nThis Sudoku cannot be solved.\n");
    }

    return 0;
}
