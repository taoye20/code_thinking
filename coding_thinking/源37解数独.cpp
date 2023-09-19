#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool backtracking(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValid(row, col, board, k)) {
                            board[row][col] = k;
                            if (backtracking(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[j][col] == val) return false;
        }
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;
        for (int i = startrow; i < startrow + 3; i++) {
            for (int j = startcol; j < startcol + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

