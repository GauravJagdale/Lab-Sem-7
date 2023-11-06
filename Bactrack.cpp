#include <iostream>

using namespace std;

const int N = 10; // Maximum board size

// Function to print the n-Queens matrix
void printMatrix(int board[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

// Function to check if a Queen can be placed in a particular cell
bool isSafe(int board[N][N], int row, int col, int n) {
    // Check the column on the left
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the n-Queens problem using backtracking
bool solveNQueens(int board[N][N], int col, int n) {
    // If all Queens are placed successfully
    if (col == n) {
        printMatrix(board, n);
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueens(board, col + 1, n) || res;
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

int main() {
    int n;
    cout << "Enter the value of n (max " << N << "): ";
    cin >> n;

    int board[N][N] = {0};

    if (n <= N) {
        // Start solving for the n-Queens problem
        if (!solveNQueens(board, 0, n)) {
            cout << "Solution does not exist." << endl;
        }
    } else {
        cout << "Board size exceeds the maximum limit (" << N << ")." << endl;
    }

    return 0;
}
