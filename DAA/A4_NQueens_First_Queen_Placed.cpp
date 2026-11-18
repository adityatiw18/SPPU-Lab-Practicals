
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board;

bool isSafe(int row, int col) {

    // Check upper diagonal (left)
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) return false;
        i--;
        j--;
    }

    // Check same row (left)
    i = row;
    j = col;
    while (j >= 0) {
        if (board[i][j] == 1) return false;
        j--;
    }

    // Check lower diagonal (left)
    i = row;
    j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == 1) return false;
        i++;
        j--;
    }

    return true;
}

bool solve(int col) {

    if (col == n) return true;

    for (int row = 0; row < n; row++) {

        if (isSafe(row, col)) {

            board[row][col] = 1;

            if (solve(col + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    board.assign(n, vector<int>(n, 0));

    if (solve(0)) {
        for (auto row : board) {
            for (int x : row)
                cout << x << " ";
            cout << endl;
        }
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}
