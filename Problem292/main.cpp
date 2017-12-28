#include <iostream>

using namespace std;

class Solution
{
public:

    bool canWinNim(int n)
    {
        return (n % 4 == 0);        //See Readme.md
    }

private:
};

int main()
{
    Solution solution;

    int stones;

    cin >> stones;

    cout << solution.canWinNim(stones) << endl;

    return 0;
}