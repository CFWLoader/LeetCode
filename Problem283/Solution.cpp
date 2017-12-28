//
// Created by cfwloader on 3/30/16.
//
#include <algorithm>

#include "Solution.h"

using namespace std;

void Solution::moveZeroes(vector<int> &nums)
{
    vector<int>::iterator zeroBegin = remove_if(nums.begin(), nums.end(), &Solution::isZero);

    while(zeroBegin != nums.end())
    {
        *zeroBegin = 0;

        ++zeroBegin;
    }
}
