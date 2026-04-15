class Solution {
public:
    int dfs(int idx, int curSum, vector<int>& nums, int target, vector<unordered_map<int, int>> &dp)
    {
        if(idx == nums.size())
            return (curSum == target);
        if(dp[idx].count(curSum))
            return dp[idx][curSum];
        // dp[sum] = number of ways to reach this sum so far 
        dp[idx][curSum] = dfs(idx+1, curSum+nums[idx], nums, target, dp) + dfs(idx+1, curSum-nums[idx], nums, target, dp);

        return dp[idx][curSum];
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        // curSum can be both positive and negative
        vector<unordered_map<int, int>> dp(n);

        // base case (i = 0)
        // dp[idex_nums][cur_sum] = this sum count
        dp[0][ nums[0]] += 1;
        dp[0][-nums[0]] += 1;

        //dp[i][sum] = number of ways to reach "sum" using first i elements
        for(int i=1;i<n;i++)
        {
            // only valid sum
            for(auto &dp_temp : dp[i-1])
            {
                int cur_sum = dp_temp.first;
                int sum_count = dp_temp.second;
                dp[i][cur_sum + nums[i]] += sum_count;
                dp[i][cur_sum - nums[i]] += sum_count;
            }
        }

        return dp[n-1][target];
        
    }
};
