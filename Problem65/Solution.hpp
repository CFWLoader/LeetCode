//
// Created by CFWLoader on 9/7/17.
//

#ifndef PROBLEM65_SOLUTION_HPP
#define PROBLEM65_SOLUTION_HPP

#include <string>

using std::string;

class Solution
{
public:
    bool isNumber(string s)
    {

//        std::cout << s << std::endl;

        if (s.size() < 1)
        {
            return false;
        }

        for (size_t idx = 0; idx < s.size(); ++idx)
        {
            if (!this->validChar(s[idx]))
            {
                return false;
            }
        }

        size_t s_idx = 0;

        for (s_idx = 0; s_idx < s.size(); ++s_idx)
        {
//            std::cout << s[s_idx] << std::endl;
            if (s[s_idx] != ' ' and s[s_idx] != 'e' and s[s_idx] != '.' and s[s_idx] != '-' and s[s_idx] != '+')
            {
//                std::cout << "Breaking:" << s_idx << std::endl;
                break;
            }
        }

//        std::cout << s_idx << ":" << s[s_idx] << std::endl;

        if (s_idx == s.size())
        {
            return false;
        }

        for (s_idx = 0; s_idx < s.size() and s[s_idx] == ' '; ++s_idx);

//        std::cout << s_idx << ":" << s[s_idx] << std::endl;

        if (s[s_idx] == 'e')
        {
            return false;
        }

        for(; s_idx < s.size() and (s[s_idx] == '-' or s[s_idx] == '+'); ++s_idx);

//        std::cout << s_idx << std::endl;

        for (; s_idx < s.size() and s[s_idx] >= '0' and s[s_idx] <= '9'; ++s_idx);

//        std::cout << s[s_idx] << std::endl;

        if (s_idx < s.size() and (s[s_idx] == 'e' or s[s_idx] == '.'))
        {
//            std::cout << "Checking:" << s[s_idx] << std::endl;
            if(s[s_idx] == '.' and s[s_idx + 1] == 'e') ++s_idx;

            for (++s_idx; s_idx < s.size() and s[s_idx] >= '0' and s[s_idx] <= '9'; ++s_idx);
        }

//        std::cout << s_idx << std::endl;

        if ((s_idx == s.size() or s[s_idx] == ' ') and s[s_idx - 1] == 'e')
        {
            return false;
        }

        for (; s_idx < s.size() and s[s_idx] == ' '; ++s_idx);

        return s_idx == s.size();

    }

    bool validChar(char ch)
    {
        return ch >= '0' and ch <= '9' or ch == 'e' or ch == '.' or ch == ' ' or ch == '-' or ch == '+';
    }
};

#endif //PROBLEM65_SOLUTION_HPP
