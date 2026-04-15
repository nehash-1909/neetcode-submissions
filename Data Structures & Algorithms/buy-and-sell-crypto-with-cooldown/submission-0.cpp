class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit = 0;

        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int i=n-1;i>=0;i--)
        {
            // buy
            dp[i][1] = max(dp[i+1][0]-prices[i], dp[i+1][1]);
            /*sell */
            if(i+2<n)
                dp[i][0] = max(dp[i+2][1]+prices[i], dp[i+1][0]);
            else
                dp[i][0] = max(prices[i], dp[i+1][0]);
        }

        return dp[0][1];
        
    }
};
