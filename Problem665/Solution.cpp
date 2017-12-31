class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int breakPoint = -1;
        
        for(int idx = 0; idx < nums.size() - 1; ++idx)
        {
            if(nums[idx] > nums[idx + 1])
            {
                breakPoint = idx + 1;
                break;
            }
        }
        
        if(breakPoint == -1)
        {
            return true;
        }
        
        if(breakPoint + 1 < nums.size())
        {
            if(nums[breakPoint - 1] > nums[breakPoint + 1])
            {
                nums[breakPoint - 1] = nums[breakPoint];
            }
            else
            {
                nums[breakPoint] = nums[breakPoint + 1];
            }
        }
        else
        {
            nums[breakPoint] = nums[breakPoint - 1];
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