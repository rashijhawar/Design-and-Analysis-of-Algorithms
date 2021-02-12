#include <stdio.h>

int nQueen(int n, int board[n][n], int col) {
    if (col >= n)
        return 1;

    for (int i = 0; i < n; i++) {
        if (isSafe(n, board, i, col)) {
            board[i][col] = 1;

            if (nQueen(n, board, col + 1))
                return 1;

            board[i][col] = 0;
        }
    }
    return 0;
}

int isSafe(int n, int board[n][n], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void printBoard(int n, int board[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", board[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int board[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (nQueen(n, board, 0) == 0)
        printf("There exists no solution for the given value of n.");
    else
        printBoard(n, board);

    return 0;
}
