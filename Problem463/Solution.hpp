//
// Created by CFWLoader on 8/2/17.
//

#ifndef PROBLEM463_SOLUTION_HPP
#define PROBLEM463_SOLUTION_HPP

#include <vector>

using std::vector;

class Solution {
public:

    int islandPerimeter(vector<vector<int>>& grid) {

        int perimeterCount = 0;

        for(int row = 0; row < grid.size(); ++row)
        {
            for(int col = 0; col < grid[row].size(); ++col)
            {
                int gridSum = 0;

                if(grid[row][col] == 0) continue;

                if(row - 1 < 0 or grid[row][col] != grid[row - 1][col])++gridSum;

                if(row + 1 >= grid.size() or grid[row][col] != grid[row + 1][col])++gridSum;

                if(col - 1 < 0 or grid[row][col] != grid[row][col - 1])++gridSum;

                if(col + 1 >= grid[row].size() or grid[row][col] != grid[row][col + 1])++gridSum;

                //printf("%d\n", gridSum);

                perimeterCount += gridSum;
            }
        }

        return perimeterCount;
    }
};

#endif //PROBLEM463_SOLUTION_HPP
