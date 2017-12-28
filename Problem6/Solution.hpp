//
// Created by cfwloader on 1/7/16.
//

#ifndef PROBLEM6_SOLUTION_HPP
#define PROBLEM6_SOLUTION_HPP

#include <string>

class Solution
{
public:
    std::string solve(const std::string& origin, int rows)
    {
        if(rows == 1)
        {
            return origin;
        }

        std::string zigZag(origin);

        int gap = 2 * (rows - 1), solidBound = zigZag.size();

        int zigIndex = 0, internalGap;

        for(int index = 0; index < solidBound; index += gap, ++zigIndex)
        {
            zigZag[zigIndex] = origin[index];
        }

        for(int rowIndex = 1; rowIndex < rows - 1; ++rowIndex)
        {
            zigZag[zigIndex++] = origin[rowIndex];

            internalGap = gap - rowIndex;

            for(int index = rowIndex + gap; index < solidBound; index += gap, internalGap += gap, ++zigIndex)
            {
                if(internalGap < solidBound)
                {
                    zigZag[zigIndex++] = origin[internalGap];
                }

                zigZag[zigIndex] = origin[index];
            }

            if(internalGap < solidBound)
            {
                zigZag[zigIndex++] = origin[internalGap];
            }

        }

        for(int index = rows - 1; index < solidBound; index += gap, ++zigIndex)
        {
            zigZag[zigIndex] = origin[index];
        }

        return zigZag;
    }
};

#endif //PROBLEM6_SOLUTION_HPP
