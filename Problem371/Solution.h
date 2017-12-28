class Solution {
public:
    int getSum(int a, int b) {

        int current;

        while(b)
        {
            current = a & b;

            a = a ^ b;

            b = current << 1;
        }

        return a;
    }
};