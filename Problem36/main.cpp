#include <iostream>
#include "Solution.h"

using namespace std;

int case1();

int main()
{
    case1();

    return 0;
}

int case1()
{
    Solution solution;

    vector<vector<char>> sudoku(9);

    for(vector<vector<char>>::iterator iterator1 = sudoku.begin(); iterator1 != sudoku.end(); ++iterator1)
    {
        iterator1->resize(9, '.');
    }

    sudoku[0][4] = '5';
    sudoku[0][7] = '1';
    sudoku[1][1] = '4';
    sudoku[1][3] = '3';
    sudoku[2][5] = '3';
    sudoku[2][8] = '1';
    sudoku[3][0] = '8';

    cout << solution.isValidSudoku(sudoku) << endl;

    return 0;
}