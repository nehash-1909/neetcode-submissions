class Solution {
public:
    int rob(vector<int>& cost) 
    {

        int n = cost.size();
        int dp[n+1] = {0};

        dp[0] = cost[0];
        dp[1] = max(cost[1], dp[0]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + cost[i]);
        }

        return dp[n-1];
        
    }
};
