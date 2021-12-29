#include <iostream>

using namespace std;

#define N 9

void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            if (j % 3 == 2 && j != 0 && j != 8) {
                cout << arr[i][j] << " | ";
            }
            else {
                cout << arr[i][j] << " ";
            }
        }
        if (i % 3 == 2 && i != 0 && i != 8) {
            cout << "\n---------------------";
        }
        cout << endl;
    }
}


bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int i = 0; i <= 8; i++)
        if (grid[i][col] == num)
            return false;


    for (int j = 0; j <= 8; j++)
        if (grid[row][j] == num)
            return false;

    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
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

    if (solveSudoku(sudoku, 0, 0)) {
        print(sudoku);
    }
    else {
        cout << "No solutions found" << endl;
    }
}
