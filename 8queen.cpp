#include <iostream>
#include <vector>

using namespace std;

#define N 8

bool isSafe(vector<vector<int>>&board, int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>&board, int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

void printSolution(vector<vector<int>>&board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
   
    vector<vector<int>>board(N,vector<int>(N,0));
    board[0][0] = 1; // First Queen placed at (0,0)
    board[1][0] = 1;
    if (!solveNQueensUtil(board, 1)) {
        cout << "Solution does not exist\n";
        return 0;
    }

    printSolution(board);
    return 0;
}
