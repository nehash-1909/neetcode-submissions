class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {

        int n = coins.size();

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // 1 2 5
        // 1 -> 1
        // 2 --> 1+1 2
        // 3 --> dp(3-2) => 1 + 1 + 1

        for(int j=1;j<=amount; j++)
        {
            for(int i=0;i<n;i++)
            {
                if(coins[i] <= j)
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
            //cout<<j<<" "<<dp[j]<<endl;
        }
        return dp[amount] > amount? -1: dp[amount];
        
    }
};
