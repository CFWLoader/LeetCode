//
// Created by cfwloader on 3/9/16.
//

#include "Solution.h"

#include <string>
#include <vector>

using namespace std;

string Solution::addBinary(string a, string b)
{
    if(a.size() < 1)
    {
        return b;
    }

    if(b.size() < 1)
    {
        return a;
    }

    size_t maxSize = (a.size() > b.size()) ? a.size() + 1 : b.size() + 1;

    vector<int> result(maxSize);

    int bitValue, current = 0;

    int resultIndex = 0;

    int aIndex = a.size () - 1, bIndex = b.size() - 1;

    while(aIndex > -1 && bIndex > -1)
    {
        bitValue = a[aIndex] - '0' + b[bIndex] - '0' + current;

        result[resultIndex] = bitValue % 2, current = bitValue / 2;

        --aIndex, --bIndex, ++resultIndex;
    }

    if(aIndex > -1)
    {
        while(aIndex > -1)
        {
            bitValue = a[aIndex] - '0' + current;

            result[resultIndex] = bitValue % 2, current = bitValue / 2;

            --aIndex, ++resultIndex;
        }
    }
    else if(bIndex > -1)
    {
        while(bIndex > -1)
        {
            bitValue = b[bIndex] - '0' + current;

            result[resultIndex] = bitValue % 2, current = bitValue / 2;

            --bIndex, ++resultIndex;
        }
    }

    if(current > 0)
    {
        result[resultIndex] = 1;

        maxSize = resultIndex + 1;
    }
    else
    {
        maxSize = resultIndex;
    }

    string str(maxSize, '0');

    for(int index = 0; index < maxSize; ++index)
    {
        str[index] = '0' + result[maxSize - index - 1];
    }

    return str;
}
