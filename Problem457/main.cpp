#include <iostream>

#include "Solution.hpp"

int main()
{

    Solution solution;

    vector<int> testCase1({2, -1, 1, -2, -2});

    cout << solution.circularArrayLoop(testCase1) << endl;

    vector<int> vector1({2, -1, 1, 2, 2});

    cout << solution.circularArrayLoop(vector1) << endl;

    vector<int> vector2({-1, 2});

    cout << solution.circularArrayLoop(vector2) << endl;

    vector<int> vector3({-2, 1, -1, -2, -2});

    cout << solution.circularArrayLoop(vector3) << endl;

    return 0;
}