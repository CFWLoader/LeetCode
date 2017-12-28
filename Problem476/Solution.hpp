//
// Created by CFWLoader on 7/28/17.
//

#ifndef PROBLEM476_SOLUTION_HPP
#define PROBLEM476_SOLUTION_HPP

class Solution {
public:
    int findComplement(int num) {

        int mask = ~0;

        while(num & mask) mask <<= 1;

        return ~mask & ~num;

    }
};

#endif //PROBLEM476_SOLUTION_HPP
