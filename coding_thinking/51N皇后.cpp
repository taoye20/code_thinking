#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    void backtracking(vector<string>& chessboard, int n, int row) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(chessboard, n, row, col)) {
                chessboard[row][col] = 'Q';
                backtracking(chessboard, n, row + 1);
                chessboard[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string>& chessboard, int n, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, n, 0);
        return result;
    }
}solution;

int main() {
    vector<vector<string>> res = solution.solveNQueens(4);
    for (vector<string> i : res) {
        for (string j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}