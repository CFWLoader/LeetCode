//
// Created by Evan on 2017/6/29.
//

#ifndef PROBLEM461_SOLUTION_HPP_H
#define PROBLEM461_SOLUTION_HPP_H

#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {

        int counter = 0;

        while(x > 0 or y > 0)
        {
            counter += (x xor y) & 1;

            x >>= 1; y >>= 1;
        }

        return counter;

    }
};

#endif //PROBLEM461_SOLUTION_HPP_H
