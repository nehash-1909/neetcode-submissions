class Solution {
public:
    int dfs(int idx, int curSum, vector<int>& nums, int target, vector<unordered_map<int, int>> &dp)
    {
        if(idx == nums.size())
            return (curSum == target);
        if(dp[idx].count(curSum))
            return dp[idx][curSum];
        
        dp[idx][curSum] = dfs(idx+1, curSum+nums[idx], nums, target, dp) + dfs(idx+1, curSum-nums[idx], nums, target, dp);

        return dp[idx][curSum];
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        // curSum can be both positive and negative
        vector<unordered_map<int, int>> dp(n);
        return dfs(0, 0, nums, target, dp);
        
    }
};
