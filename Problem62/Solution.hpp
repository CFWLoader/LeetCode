class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int steps = m + n - 2, downSteps = m - 1;
        
        // Solution is C(N, k), N -> steps, k -> downSteps.
        double combi = 1;
        
        for(int i = 1; i <= downSteps; ++i)
        {
            combi = combi * (steps - downSteps + i) / i;
        }
        
        return int(combi);
    }
};
