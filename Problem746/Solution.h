//
// Created by CFWLoader on 1/5/18.
//

#ifndef PROBLEM746_SOLUTION_H
#define PROBLEM746_SOLUTION_H

#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() < 2)
        {
            return 0;
        }
        int case1 = cost[0], case2 = cost[1];
        for(int i = 2; i < cost.size(); i++)
        {
            int stand = min(case1, case2) + cost[i];
            case1 = case2;
            case2 = stand;
        }

        return min(case1, case2);
    }
};

#endif //PROBLEM746_SOLUTION_H
