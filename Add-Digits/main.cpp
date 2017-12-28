#include <iostream>

using namespace std;

int main()
{
    int num;

    cin >> num;

    int extracted;

    while(num >= 10)
    {
        extracted = 0;

        while(num > 0)
        {
            extracted = extracted + num % 10;

            num = num / 10;
        }

        num = extracted;
    }

    cout << num << endl;

    return 0;
}