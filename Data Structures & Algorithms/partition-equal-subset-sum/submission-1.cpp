class Solution {
public:
    bool part(vector<int>& nums, int idx, int target)
    {
        if(idx == nums.size())
            return false;
        
        if(target == 0)
            return true;
        
        return part(nums, idx+1, target-nums[idx]) || part(nums, idx+1, target); 
    }
    bool canPartition(vector<int>& nums) 
    {

        int sum = 0;
        for(int i:nums)
        {
            sum += i;
        }
        if(sum%2 == 1)
            return false;

        int n = nums.size();

        int target = sum/2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for(int i=0;i<n;i++)
        {
            for(int j=target; j>=0;j--)
            {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[target];
       
    }
};
