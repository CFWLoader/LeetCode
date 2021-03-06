//
// Created by Evan on 2017/6/29.
//

#ifndef PROBLEM535_SOLUTION_H
#define PROBLEM535_SOLUTION_H

#include <string>
#include <unordered_map>
#include <time.h>

using std::string;
using std::unordered_map;

class Solution{
public:
    Solution() {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.count(longUrl)) {
            return "http://tinyurl.com/" + long2short[longUrl];
        }
        int idx = 0, val = 0;
        string randStr;
        for (int i = 0; i < 6; ++i) randStr.push_back(dict[rand() % 62]);
        while (short2long.count(randStr)) {
            randStr[idx] = dict[rand() % 62];
            idx = (idx + 1) % 5;
        }
        short2long[randStr] = longUrl;
        long2short[longUrl] = randStr;
        return "http://tinyurl.com/" + randStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return short2long.count(randStr) ? short2long[randStr] : shortUrl;
    }

private:
    unordered_map<string, string> short2long, long2short;
    string dict;
};

#endif //PROBLEM535_SOLUTION_H
