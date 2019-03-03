/*
 * Codewars kata
 * Sudoku Solution Validator (529bf0e9bdf7657179000008)
 */

#include <iostream>

using namespace std;

bool validSolution(unsigned int board[9][9]) {
    for (int j = 0 ; j < 9; ++j) {
        for (int i = 0; i < 9; ++i) {
            if (board[j][i] > 9) {
                return false;
            }
        }
    }
    for (int j = 0; j < 9; ++j) {
        unsigned int s1 { 0 };
        unsigned int s2 { 0 };
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < i; ++k) {
                if (board[j][i] == board[j][k] || board[i][j] == board[k][j]) {
                    return false;
                }
            }
            s1 += board[j][i];
            s2 += board[i][j];
        }
        if (s1 != 45 || s2 != 45) {
            return false;
        }
    }
    for (int qj = 0; qj < 3; ++qj) {
        for (int qi = 0; qi < 3; ++qi) {
            unsigned int s { 0 };
            for (int j = 0; j < 3; ++j) {
                for (int i = 0; i < 3; ++i) {
                    for (int l = 0; l < 3; ++l) {
                        for (int k = 0; k < 3; ++k) {
                            if (j != l && i != k && board[qj * 3 + j][qi * 3 + i] == board[qj * 3 + l][qi * 3 + k]) {
                                return false;
                            }
                        }
                    }
                s += board[qj * 3 + j][qi * 3 + i];
                }
            }
            if (s != 45) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    cout << validSolution(example1) << endl;
    return 0;
}
