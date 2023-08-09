#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

bool solveNQueens(int row) {
    if (row >= N) {
        return true;
    }
    
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            
            if (solveNQueens(row + 1)) {
                return true;
            }
            
            board[row][col] = 0;
        }
    }
    
    return false;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (solveNQueens(0)) {
        printf("Solution found:\n");
        printBoard();
    } else {
        printf("No solution exists for N = %d\n", N);
    }
}
