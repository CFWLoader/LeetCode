//
// Created by CFWLoader on 8/2/17.
//

#ifndef PROBLEM412_SOLUTION_HPP
#define PROBLEM412_SOLUTION_HPP

#include<vector>
#include<string>
#include<sstream>

using std::vector;
using std::string;
using std::stringstream;

class Solution {
public:

    static const string FIZZ_BUZZ[];

    vector<string> fizzBuzz(int n) {

        vector<string> result(n);

        stringstream ss;

        for(int idx = 1; idx <= n; ++idx)
        {
            if(idx% 3 == 0 and idx % 5 == 0)
            {
                result[idx - 1] = FIZZ_BUZZ[2];
            }
            else if(idx % 3 == 0)
            {
                result[idx - 1] = FIZZ_BUZZ[0];
            }
            else if(idx % 5 == 0)
            {
                result[idx - 1] = FIZZ_BUZZ[1];
            }
            else
            {
                ss << idx;

                ss >> result[idx - 1];

                ss.clear();
            }
        }

        return result;
    }
};

const string Solution::FIZZ_BUZZ[] = {"Fizz", "Buzz", "FizzBuzz"};

#endif //PROBLEM412_SOLUTION_HPP
