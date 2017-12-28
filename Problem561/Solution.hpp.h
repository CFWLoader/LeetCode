//
// Created by CFWLoader on 7/27/17.
//

#ifndef PROBLEM561_SOLUTION_HPP_H
#define PROBLEM561_SOLUTION_HPP_H

#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        int result = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2)
        {
            result += nums[i];
        }

        return result;

    }
};

#endif //PROBLEM561_SOLUTION_HPP_H
