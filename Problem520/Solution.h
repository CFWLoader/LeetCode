//
// Created by CFWLoader on 1/3/18.
//

#ifndef PROBLEM520_SOLUTION_H
#define PROBLEM520_SOLUTION_H

class Solution {
public:
    bool detectCapitalUse(string word) {

        if(word.size() == 1)
        {
            return true;
        }

        int base;

        if(word[0] < 'a' and word[1] < 'a')
        {
            base = 'A';
        }
        else if(word[0] < 'a' and word[1] >= 'a')
        {
            base = 'a';
        }
        else if(word[0] >= 'a' and word[1] >= 'a')
        {
            base = 'a';
        }
        else
        {
            return false;
        }

        for(int idx = 2; idx < word.size(); ++idx)
        {
            if(word[idx] - base < 0 or word[idx] - base > 26)
            {
                return false;
            }
        }

        return true;
    }
};

#endif //PROBLEM520_SOLUTION_H
