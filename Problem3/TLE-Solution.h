//
// Created by cfwloader on 10/18/15.
//

#ifndef PROBLEM3_TLE_SOLUTION_H
#define PROBLEM3_TLE_SOLUTION_H

#include <iosfwd>
#include <map>

class Solution {
public:
    static int lengthOfLongestSubstring(std::string s) {

        std::map<char, int> present;

        int maxLength = 0, currentLength = 0;

        unsigned long length = s.length();

        for(int index = 0; index < length; ++index)
        {
            if(!present[s[index] - 'a'])
            {
                present[s[index] - 'a'] = 1;

                ++currentLength;

                continue;
            }
            else
            {
                index = index - currentLength + 1;

                if(currentLength > maxLength)
                {
                    maxLength = currentLength;
                }

                currentLength = 0;

                for(std::map<char, int>::iterator iterator1 = present.begin(), endOfMap = present.end();
                    iterator1 != endOfMap;
                    ++iterator1)
                {
                    iterator1->second = 0;
                }

                present[s[index] - 'a'] = 1;

                ++currentLength;
            }
        }

        if(currentLength > maxLength)
        {
            maxLength = currentLength;
        }

        return maxLength;
    }
};

#endif //PROBLEM3_TLE_SOLUTION_H
