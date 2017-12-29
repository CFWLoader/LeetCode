//
// Created by CFWLoader on 12/29/17.
//

#ifndef PROBLEM718_SOLUTION_HPP
#define PROBLEM718_SOLUTION_HPP

#include <vector>

using std::vector;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {

        if(A.size() < 1 or B.size() < 1)
        {
            return 0;
        }

        vector<vector<int>> memo(A.size());

        for(int idx = 0; idx < memo.size(); ++idx)
        {
            memo[idx].resize(B.size());
        }

        int upVal, leftVal, maxMatched = 0;

        for(int i = 0; i < memo.size(); ++i)
        {
            for(int j = 0; j < memo[i].size(); ++j)
            {
                upVal = i - 1 >= 0 ? memo[i - 1][j] : 0;

                leftVal = j - 1 >= 0 ? memo[i][j - 1] : 0;

                memo[i][j] = (upVal > leftVal ? upVal : leftVal) + (A[i] == B[j] ? 1 : 0);

                memo[i][j] = memo[i][j] > i + 1 ? i + 1 : memo[i][j];

//                std::cout << "(" << i << "," << j << "," << "A[" << A[i] << "],B["<< B[j] << "]," << memo[i][j] << ") ";

            }

//            std::cout << std::endl;
        }

        return memo[A.size() - 1][B.size() - 1];

    }
};

#endif //PROBLEM718_SOLUTION_HPP
