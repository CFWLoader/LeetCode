//
// Created by CFWLoader on 12/29/17.
//

#ifndef PROBLEM282_SOLUTION_HPP
#define PROBLEM282_SOLUTION_HPP

#include <vector>

using std::vector;
using std::string;

using std::cout;
using std::endl;

class Solution {
public:
    vector<string> addOperators(string num, int target) {

        if(num.size() < 1)
        {
            return vector<string>();
        }

        vector<vector<int>> combinations;

        for(int len = 1; len <= num.size(); ++len)
        {
            vector<int> preSeq;

            preSeq.push_back(this->convertInt(num, 0, len));

            this->generateCombinations(combinations, preSeq, num, len);
        }

//        cout << "-----------Result-----------" << endl;
//        for(auto seq : combinations)
//        {
//            printIntVec(seq);
//        }

        int sum = 0;

        vector<string> resultStrings;

        for(auto combi : combinations)
        {
            sum = combi[0];

            if(combi.size() == 1)
            {
                if(sum == target)
                {

                }
            }
        }

        return vector<string>();

    }

    void generateCombinations(vector<vector<int>>& combinations, const vector<int>& preSeq, string num, int startIdx)
    {
        if(startIdx >= num.size())
        {
            combinations.push_back(vector<int>(preSeq.begin(), preSeq.end()));
            return;
        }

        for(int len = 1; startIdx + len <= num.size(); ++len)
        {
            vector<int> curPreSeq(preSeq.begin(), preSeq.end());

//            cout << "Getting: " << convertInt(num, startIdx, len) << endl;

            curPreSeq.push_back(this->convertInt(num, startIdx, len));

            this->generateCombinations(combinations, curPreSeq, num, startIdx + len);
        }
    }

    int convertInt(const string& num, int startIdx, int len)
    {
        int val = 0;

        for(int idx = startIdx; idx < startIdx + len; ++idx)
        {
            val = val * 10 + num[idx] - '0';
        }

        return val;
    }

    void printIntVec(const vector<int>& vec)
    {
        cout << "[";
        for(auto val :vec)
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

//    void generateCombinations(vector<vector<int>>& combinations, string num, int startIdx)
//    {
//        if(startIdx == nums.size())
//        {
//            return;
//        }
//    }
};

#endif //PROBLEM282_SOLUTION_HPP
