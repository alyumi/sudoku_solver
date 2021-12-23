// sudoku solver.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;

bool isNumInCol(int current_sudoku[9][9], int new_row, int new_col) {
    for (int i = 0; i < 9; i++) {
        if (new_row != i && current_sudoku[i][new_col] != -1 && current_sudoku[i][new_col] == current_sudoku[new_row][new_col]) {
            return true;
        }
    }
    return false;
}

bool isNumInRow(int current_sudoku[9][9], int new_row, int new_col) {
    for (int j = 0; j < 9; j++) {
        if (new_col != j && current_sudoku[new_row][j] != -1 && current_sudoku[new_row][j] == current_sudoku[new_row][new_col]) {
            return true;
        }
    }
    return false;
}

bool isNumInBox(int current_sudoku[9][9], int new_row, int new_col) {

    for (int i = new_row - new_row % 3; i < new_row + (3 - new_row % 3); i++) {
        for (int j = new_col - new_col % 3; j < new_col + (3 - new_col % 3); j++) {
            if (new_col != j && new_row != i && current_sudoku[i][j] != -1 && current_sudoku[i][j] == current_sudoku[new_row][new_col]) {
                return true;
            }
        }
    }
    return false;
}


void solve(int sudoku[9][9]) {
    int current_sudoku[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            current_sudoku[i][j] = sudoku[i][j];
        }
    }

    current_sudoku[0][0] = 6;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!isNumInCol(current_sudoku, i, j)) {
                cout << i << " " << j << " Not in Col" << endl;
            }
            else {
                cout << i << " " << j << " In Col" << endl;
            }
            if (!isNumInRow(current_sudoku, i, j)) {
                cout << i << " " << j << " Not in Row" << endl;
            }
            else {
                cout << i << " " << j << " In Row" << endl;
            }
            if (!isNumInBox(current_sudoku, i, j)) {
                cout << i << " " << j << " Not in Box" << endl << endl;
            }
            else {
                cout << i << " " << j << " In Box" << endl << endl;
            }
        }
    }
}



int main()
{
    int sudoku[9][9] = { {-1, 6, 1, 4, -1, 8, -1, -1, 7},
                           {-1, -1, -1, -1, -1, 1, 2, 9, -1},
                           {-1, -1, -1, -1, 3, 9, -1, -1, -1},
                           {7, -1, -1, -1, -1, 4, 5, 1, 6},
                           {-1, 2, -1, 1, -1, -1, 9, -1, -1},
                           {1, 4, 8, 9, -1, -1, 7, -1, 3},
                           {3, 9, 6, 8, 4, 5, -1, -1, 2},
                           {-1, -1, -1, 3, -1, 2, 8, -1, 9},
                           {8, -1, 2, -1, 9, 7, -1, 3, -1} };


    solve(sudoku);
}
