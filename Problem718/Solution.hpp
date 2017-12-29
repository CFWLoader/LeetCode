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

        vector<vector<int>> memo(A.size(), vector<int>(B.size()));

        for(int i = 0; i < memo.size(); ++i) memo[i][0] = A[i] == B[0] ? 1 : 0;
        for(int j = 0; j < memo[0].size(); ++j) memo[0][j] = A[0] == B[j] ? 1 : 0;

        int maxVal = 0;

        for(int i = 1; i < memo.size(); ++i)
        {
            for(int j = 1; j < memo[i].size(); ++j)
            {
                if(A[i] == B[j])
                {
                    memo[i][j] = memo[i - 1][j - 1] + 1;

                    if(memo[i][j] > maxVal)
                    {
//                        std::cout << "New max:" << memo[i][j] << std::endl;
                        maxVal = memo[i][j];
                    }
                }
            }

        }

//        for(int i = 0; i < memo.size(); ++i)
//        {
//            for(int j = 0; j < memo[i].size(); ++j)
//            {
//                std::cout << "(" << i << "," << j << "," << "A[" << A[i] << "],B["<< B[j] << "]," << memo[i][j] << ") ";
//            }
//            std::cout << std::endl;
//        }

        return maxVal;

    }
};

#endif //PROBLEM718_SOLUTION_HPP
