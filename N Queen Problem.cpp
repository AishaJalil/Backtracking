#include <iostream>
using namespace std;

// Function to print the chessboard
void printBoard(int **board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **board, int row, int col, int n) {
    // Check the column
    for (int i = 0; i < row; ++i) {
        if (board[i][col]==1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]==1) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j]==1) {
            return false;
        }
    }

    return true;
}

bool solveQueens(int **board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveQueens(board, row + 1, n))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the size of board (N): ";
    cin >> n;

    int **board = new int *[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;  // Initialize the board to zeros
        }
    }

    if (solveQueens(board, 0, n)) {
        cout << "Solution found!\n";
        printBoard(board, n);
    } else {
        cout << "No solution found.\n";
    }

    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
