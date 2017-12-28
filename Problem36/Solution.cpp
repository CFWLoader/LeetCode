//
// Created by cfwloader on 3/9/16.
//

#include <iostream>
#include "Solution.h"

bool Solution::isValidSudoku(vector<vector<char>> &board)
{
    // Validate the matrix.
    if(board.size() != 9)
    {
        return false;
    }

    for (vector<vector<char>>::iterator iterator = board.begin(); iterator != board.end(); ++iterator)
    {
        if(iterator->size() != 9)
        {
            return false;
        }
    }

    bool presented[10];

    // Check Columns.
    for(int row = 0; row < board.size(); ++row)
    {
        for (int i = 0; i < 10; ++i)
        {
            presented[i] = false;
        }

        for (int col = 0; col < board[row].size(); ++col)
        {
            if(board[row][col] == '.')
            {
                continue;
            }

            if(presented[board[row][col] - '0'])
            {
                return false;
            }
            else
            {
                presented[board[row][col] - '0'] = true;
            }
        }
    }

    // Check rows.
    for(int row = 0; row < board.size(); ++row)
    {
        for (int i = 0; i < 10; ++i)
        {
            presented[i] = false;
        }

        for (int col = 0; col < board[row].size(); ++col)
        {
            if(board[col][row] == '.')
            {
                continue;
            }

            if(presented[board[col][row] - '0'])
            {
                return false;
            }
            else
            {
                presented[board[col][row] - '0'] = true;
            }
        }
    }

    // Check blocks.
    for (int blockRow = 1; blockRow < 4; ++blockRow)
    {
        for (int blockCol = 1; blockCol < 4 ; ++blockCol)
        {

            for (int i = 0; i < 10; ++i)
            {
                presented[i] = false;
            }

            // std::cout << "Block bound:" << (blockRow - 1) * 3 << "-" << blockRow * 3 - 1 << ", "  << (blockCol - 1) * 3 << "-" << blockCol * 3 - 1<< std::endl;

            for (int row = (blockRow - 1) * 3; row <= blockRow * 3 - 1; ++row)
            {
                for (int col = (blockCol - 1) * 3; col <= blockCol * 3 - 1; ++col)
                {

                    if(board[row][col] == '.')
                    {
                        continue;
                    }

                    /*
                    if(row >= 0 && row < 3 && col > 2 && col < 6)
                    {
                        printf("(%d,%d)->%c, present:%d\n", row, col, board[row][col], presented[board[row][col] - '0']);
                    }
                     */

                    if(presented[board[row][col] - '0'])
                    {
                        return false;
                    }
                    else
                    {
                        presented[board[row][col] - '0'] = true;
                    }
                }
            }
        }
    }

    return true;
}
