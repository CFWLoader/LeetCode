class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int violations = 0;
        
        for(int idx = 0; idx < nums.size() - 1; ++idx)
        {
            if(nums[idx] > nums[idx + 1])
            {
                nums[idx] = nums[idx + 1];
                ++violations;
            }
            
            if(violations > 1)
            {
                return false;
            }
        }
        
        for(int idx = 0; idx < nums.size() - 1; ++idx)
        {
            if(nums[idx] > nums[idx + 1])
            {
                return false;
            }
        }
        
        return true;
        
    }
};