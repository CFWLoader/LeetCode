#include <iostream>

#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        string::const_iterator targetHead = s.begin(), targetEnd = s.end();

        int stringBound = s.size();

        int leftIndex = 0, rightIndex = 0, palindromeSize = 1, currentPalindromeSize;

        int left, right, distance;

        for (int palidromePivot = 0; palidromePivot < stringBound; ++palidromePivot)    // The increment of variable palidromePivot can be optimized.
        {

            leftIndex = palidromePivot - 1, rightIndex = palidromePivot + 1;

            currentPalindromeSize = 1;

            while(rightIndex < stringBound and s[palidromePivot] == s[rightIndex])
            {
                ++rightIndex;                   // Pure palindrome.
                ++currentPalindromeSize;
            }

            while (leftIndex >= 0 and rightIndex < stringBound)
            {
                if (s[leftIndex] != s[rightIndex])break;

                --leftIndex, ++rightIndex;

                currentPalindromeSize += 2;
            }

            if (currentPalindromeSize > palindromeSize)
            {
                palindromeSize = currentPalindromeSize;

                targetHead = s.begin(), targetEnd = s.begin();

                left = leftIndex + 1, right = rightIndex;

                advance(targetHead, left);
                advance(targetEnd, right);

                //cout << string(targetHead, targetEnd) << "  Start Index:" << left << "   Pivot:" << palidromePivot << "  End Index:" << right << endl;

            }

            //distance = (palidromePivot - leftIndex - 1) < (rightIndex - palidromePivot) ? palidromePivot - leftIndex - 1: rightIndex - palidromePivot;

            //distance = distance > 0 ? distance : 1;

            //cout << distance << endl;
        }

        return string(targetHead, targetEnd);
    }
};

int main()
{
    Solution solution;

    string str = "abadd";

    string result = solution.longestPalindrome(str);

    cout << result << endl;

    return 0;
}