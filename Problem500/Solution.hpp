//
// Created by CFWLoader on 7/31/17.
//

#ifndef PROBLEM500_SOLUTION_HPP
#define PROBLEM500_SOLUTION_HPP

#include <string>
#include <vector>

using std::vector;
using std::string;

static const vector<vector<char>> KEY_MAP = {
        {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
        {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
        {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
};

static const unsigned CONVERT_VALUE = 'a' - 'A';

class Solution {
public:

    vector<string> findWords(vector<string>& words) {

        vector<string> result;

        for(vector<string>::iterator wordIter = words.begin();
                wordIter != words.end();
                ++wordIter)
        {
            if(wordIter->size() == 0)continue;

            if(this->isSubsetToAnyRow(*wordIter))
            {
                result.push_back(*wordIter);
            }
        }

        return result;
    }

    bool isSubsetToAnyRow(const string& str)
    {
        size_t rowNum = matchRowNum(str[0]);

        bool matched;

        for(string::const_iterator chIter = str.begin();
                chIter != str.end();
                ++chIter)
        {
            matched = false;

            for(vector<char>::const_iterator mapChIter = KEY_MAP[rowNum].begin();
                mapChIter != KEY_MAP[rowNum].end();
                ++mapChIter)
            {
                if(fixCharValue(*chIter) == *mapChIter)
                {
                    matched = true;

                    break;
                }
            }

            if(!matched)return false;
        }

        return true;
    }

    size_t matchRowNum(char ch)
    {
        static const size_t ROWS_LIMIT = KEY_MAP.size();

        for(size_t idx = 0; idx < ROWS_LIMIT; ++idx)
        {
            for(vector<char>::const_iterator chIter = KEY_MAP[idx].begin();
                    chIter != KEY_MAP[idx].end();
                    ++chIter)
            {
                if(fixCharValue(ch) == *chIter)
                {
                    return idx;
                }
            }
        }

        return ROWS_LIMIT;
    }

    char fixCharValue(char ch)
    {
        if(ch >= 'A' and ch <= 'Z')
        {
            ch += CONVERT_VALUE;
        }

        return ch;
    }

};

#endif //PROBLEM500_SOLUTION_HPP
