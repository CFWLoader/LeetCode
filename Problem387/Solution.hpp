//
// Created by CFWLoader on 9/11/17.
//

#ifndef PROBLEM387_SOLUTION_HPP
#define PROBLEM387_SOLUTION_HPP

#include <string>

using std::string;

class Solution {
public:
    int firstUniqChar(string s) {

        size_t start_idx = 0, lmt = s.size(), iter_idx;

        bool uniq_find;

        while(start_idx < lmt)
        {
            iter_idx = start_idx + 1;

            uniq_find = true;

            while(iter_idx < lmt)
            {
                if(s[iter_idx] == s[start_idx])
                {
                    uniq_find = false;

                    s[iter_idx] = 'A';
                }

                ++iter_idx;
            }

            if(uniq_find)
            {
                return start_idx;
            }

            ++start_idx;

            while(start_idx < lmt and s[start_idx] == 'A')++start_idx;
        }

        return -1;

    }
};

#endif //PROBLEM387_SOLUTION_HPP
