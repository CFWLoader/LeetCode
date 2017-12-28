//
// Created by cfwloader on 3/18/16.
//

#include "Solution.h"

string Solution::convertToTitle(int n)
{

    int tail = 0, index = 0;

    char chars[128];

    while(n > 0)
    {
        tail = n % 26;

        tail = (tail + 25) % 26;

        chars[index] = 'A' + tail;

        n = n / 26 - (n % 26 == 0 ? 1 : 0);

        ++index;
    }

    chars[index] = '\0';

    string resultBuffer(chars);

    return string(resultBuffer.rbegin(), resultBuffer.rend());
}
