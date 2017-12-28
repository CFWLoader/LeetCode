#include <iostream>

#include "Solution.hpp"

int main()
{
    Solution solution;

    //string ans = solution.complexNumberMultiply("1+1i", "1+1i");
    //solution.complexNumberMultiply("1+-1i", "-1+1i");
    //solution.complexNumberMultiply("-3+-1i", "-1+1i");
    string ans = solution.complexNumberMultiply("1+-1i", "1+-1i");

    cout << ans << endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}