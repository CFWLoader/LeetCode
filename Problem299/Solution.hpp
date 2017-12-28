//
// Created by Evan on 2016/3/16.
//

#ifndef PROBLEM299_SOLUTION_HPP
#define PROBLEM299_SOLUTION_HPP


#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    string getHint(string secret, string guess) {

        int index, size = secret.size();

        int bulls = 0,  cows = 0;

        int statistic[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for(index = 0; index < size; ++ index)
        {
            if(secret[index] == guess[index])
            {
                ++bulls;

                secret[index] = guess[index] = 'x';
            }
        }

        for(index = 0; index < size; ++index)
        {
            if(secret[index] == 'x') continue;

            ++statistic[secret[index] - '0'];
        }

        for(index = 0; index < size; ++index)
        {
            if(guess[index] == 'x') continue;

            if(statistic[guess[index] - '0'] > 0)
            {
                ++cows;

                --statistic[guess[index] - '0'];
            }
        }

        char resultString[128];

        snprintf(resultString, 128, "%dA%dB", bulls, cows);

        return string(resultString);
    }
};

#endif //PROBLEM299_SOLUTION_HPP_H
