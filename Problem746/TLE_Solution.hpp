//
// Created by CFWLoader on 1/5/18.
//

#ifndef PROBLEM746_SOLUTION_HPP
#define PROBLEM746_SOLUTION_HPP

#include <vector>

using std::vector;

/**
 * Brute Force Search.
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int caseOne = moveForward(cost, 0);
        int caseTwo = moveForward(cost, 1);

        return caseOne < caseTwo ? caseOne : caseTwo;

    }

    int moveForward(vector<int>& cost, int stepIndex)
    {
        if(stepIndex >= cost.size())
        {
            return 0;
        }

        int caseOne = cost[stepIndex] + moveForward(cost, stepIndex + 1);
        int caseTwo = cost[stepIndex] + moveForward(cost, stepIndex + 2);

        return caseOne < caseTwo ? caseOne : caseTwo;
    }
};

#endif //PROBLEM746_SOLUTION_HPP
