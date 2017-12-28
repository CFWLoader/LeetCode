//
// Created by CFWLoader on 7/27/17.
//

#ifndef PROBLEM537_SOLUTION_HPP
#define PROBLEM537_SOLUTION_HPP

#include <string>

using namespace std;

class Solution {
public:

    pair<int,int> extract(string data)
    {
        pair<int, int> result(0, 0);

        size_t pos = 0;

        while(data[pos] != '+') ++pos;

        result.first = atoi(data.c_str());

        result.second = stoi(&data.c_str()[pos + 1]);

        return result;
    }

    string complexNumberMultiply(string a, string b) {

        pair<int, int> a_val = this->extract(a);
        pair<int, int> b_val = this->extract(b);

        // cout << a_val.first << "  " <<  a_val.second << endl;
        // cout << b_val.first << "  " <<  b_val.second << endl;

        char buf[256];

        snprintf(buf, 256, "%d+%di",
                 a_val.first * b_val.first - a_val.second * b_val.second,
                 a_val.first * b_val.second + a_val.second * b_val.first
        );

        return string(buf);
    }
};

#endif //PROBLEM537_SOLUTION_HPP
