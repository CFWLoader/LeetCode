#include<vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t arrlen = nums.size();
        vector<int> dp(arrlen);
        dp[0] = nums[0];
        int maxval = dp[0];
        for(size_t idx = 1; idx < arrlen; ++idx)
        {
            dp[idx] = (dp[idx - 1] > 0 ? dp[idx - 1] : 0) + nums[idx];
            maxval = maxval < dp[idx] ? dp[idx] : maxval;
        }
        return maxval;
    }
};