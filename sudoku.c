#include <stdio.h>
#include <math.h>

int solveSudoku(int n, int sudoku[n][n], int row, int col) {
    if (row == n - 1 && col == n)
        return 1;

    if (col == n) {
        row++;
        col = 0;
    }

    if (sudoku[row][col] != 0)
        return solveSudoku(n, sudoku, row, col+1);

    for (int i = 1; i <= n; i++) {
        if (isSafe(n, sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solveSudoku(n, sudoku, row, col+1))
                return 1;
        }
         sudoku[row][col] = 0;
    }

    return 0;
}

int isSafe(int n, int sudoku[n][n], int row, int col, int num) {
    for (int i = 0; i < n; i++)
        if (sudoku[row][i] == num)
            return 0;

    for (int i = 0; i < n; i++)
        if (sudoku[i][col] == num)
            return 0;

    int startRow = row - row % (int)sqrt(n);
    int startCol = col - col % (int)sqrt(n);
    for (int i = 0; i < sqrt(n); i++)
        for (int j = 0; j < sqrt(n); j++)
            if (sudoku[startRow + i][startCol + j] == num)
                return 0;

    return 1;
}

void printSudoku(int n, int sudoku[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", sudoku[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Note: The size of the Sudoku grid should be a perfect square.");
    printf("\nEnter the size of the Sudoku grid: ");
    scanf("%d", &n);

    int sudoku[n][n];
    printf("\nEnter the Sudoku puzzle. Use 0 for blank cells:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &sudoku[i][j]);

    if (solveSudoku(n, sudoku, 0, 0)) {
        printf("\n\nSolved Sudoku:\n");
        printSudoku(n, sudoku);
    } else
        printf("\nThere exists no solution for the given Sudoku.");

    return 0;
}
