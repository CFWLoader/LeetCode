//
// Created by CFWLoader on 8/2/17.
//

#ifndef PROBLEM496_SOLUTION_HPP
#define PROBLEM496_SOLUTION_HPP

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

        vector<int> targets(findNums.size(), -1);

        vector<int>::iterator targetIter = targets.begin();

        for(vector<int>::const_iterator findNumIter = findNums.begin();
                findNumIter != findNums.end();
                ++findNumIter, ++targetIter)
        {
            bool matched = false;

            for(vector<int>::const_iterator numIter = nums.begin();
                    numIter != nums.end();
                    ++numIter)
            {
                if(*findNumIter == *numIter)matched = true;

                if(matched && *numIter > *findNumIter)
                {
                    *targetIter = *numIter;
                    break;
                }
            }
        }

        return targets;
    }
};

#endif //PROBLEM496_SOLUTION_HPP
