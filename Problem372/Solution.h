//
// Created by CFWLoader on 1/11/18.
//

#ifndef PROBLEM372_MATHSOLUTION_H
#define PROBLEM372_MATHSOLUTION_H

#include <vector>

using std::vector;

class Solution {
    const int base = 1337;
    int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
//        if (b.empty()) return 1;
//        int last_digit = b.back();
//        b.pop_back();
//        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
        if(b.empty())
        {
            return 1;
        }

        int remainder = 1;

        for(auto rIter = b.rbegin(); rIter != b.rend(); ++rIter)
        {

        }

        return remainder;
    }
};

#endif //PROBLEM372_MATHSOLUTION_H
