//
// Created by cfwloader on 3/2/16.
//

#include "Solution.h"

#include <string>
#include <iostream>

int Solution::myAtoi(const std::string& str)
{
    int number = 0;

    int newNumber = 0;

    int index = 0;

    int validCount = 0;

    bool negativeFlag = false;

    bool overFlow = false;

    while(index < str.size() && str[index] == ' ')
    {
        ++index;
    }

    if(index >= str.size())
    {
        return number;
    }

    if(str[index] == '-')
    {
        negativeFlag = true;
        ++index;

        if(index < str.size() && str[index] == '+')
        {
            return number;
        }
    }
    else if(str[index] == '+')
    {
        ++index;

        if(index < str.size() && str[index] == '-')
        {
            return number;
        }
    }
    else if(str[index] < '0' || str[index] > '9')
    {
        return number;
    }

    while(index < str.size())
    {
        if(str[index] >= '0' && str[index] <= '9')
        {
            newNumber = number * 10 + str[index] - '0';

            ++validCount;

            if(newNumber < 0 || validCount > 10)
            {
                overFlow = true;

                break;
            }
        }
        else
        {
            break;
        }

        number = newNumber;

        ++index;
    }

    if(negativeFlag && overFlow)
    {
        return -2147483648;
    }
    else if(overFlow)
    {
        number = 2147483647;
    }

    return negativeFlag ? -number : number;
}
