class Solution {
public:
    int burstBallon(vector<int>& num, int l, int r, vector<vector<int>>& dp)
    {
        if(l>r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        for(int i=l;i<=r;i++)
        {
            int ans = num[l-1] * num[i] * num[r+1];
            dp[l][r] = max({dp[l][r],ans +burstBallon(num, l, i-1,dp)+burstBallon(num, i+1, r,dp)});
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n+2, vector<int>(n+2,-1));

        return burstBallon(nums, 1, n-2,dp);

        
    }
};
