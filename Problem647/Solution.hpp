//
// Created by CFWLoader on 8/3/17.
//

#ifndef PROBLEM647_SOLUTION_HPP
#define PROBLEM647_SOLUTION_HPP

#include <string>

using std::string;

class Solution {
public:
    int countSubstrings(string s) {

        int maxLength = s.length();

        int palindromicCounter = maxLength;

        for(int palindromicLengthLimit = 2; palindromicLengthLimit <= maxLength; ++palindromicLengthLimit)
        {
            int chkStartIdx = 0, chkEndIdx = maxLength - palindromicLengthLimit;

            // printf("CSI:%d, CEI:%d\n", chkStartIdx, chkEndIdx);

            int left, right;

            while(chkStartIdx <= chkEndIdx)
            {
                left = chkStartIdx, right = chkStartIdx + palindromicLengthLimit - 1;

                //printf("L:%d, R:%d\n", left, right);

                while(left < right)
                {
                    if(s[left] != s[right])break;

                    ++left, --right;
                }

                if(left >= right)++palindromicCounter;

                ++chkStartIdx;
            }
        }

        return palindromicCounter;
    }
};

#endif //PROBLEM647_SOLUTION_HPP
