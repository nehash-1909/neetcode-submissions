class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1] = {0};
        dp[0] = 0;
        dp[1] = 0;
        //dp[2] = min(dp[0]+cost[2], dp[1]);
        for(int i=2;i<=n;i++)
        {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
            //cout<<i<<" "<<dp[i-1]<<" "<<dp[i-2]<<" "<<cost[i]<<endl;
        }

        return dp[n];
        
    }
};
