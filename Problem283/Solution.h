//
// Created by cfwloader on 3/30/16.
//

#ifndef PROBLEM283_SOLUTION_H
#define PROBLEM283_SOLUTION_H

#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums);

    static bool isZero(int num)
    {
        return num == 0;
    }
};


#endif //PROBLEM283_SOLUTION_H
