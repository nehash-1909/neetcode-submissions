class Solution {
public:
    int cost(int start, int end, vector<int>& nums) 
    {
        int n = nums.size();
        int dp[n+1] = {0};
        dp[start] = nums[start];
        dp[start+1] = max(dp[start], nums[start+1]);

        for(int i=start+2;i<=end;i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(cost(0, n-2, nums), cost(1, n-1, nums));
        
    }
};
