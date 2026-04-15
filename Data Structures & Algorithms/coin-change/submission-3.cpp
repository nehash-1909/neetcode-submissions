class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {

        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX-1);
        dp[0] = 0;

        // 1 2 5
        // 1 -> 1
        // 2 --> 1+1 2
        // 3 --> dp(3-2) => 1 + 1 + 1

        for(int j=1;j<=amount; j++)
        {
            for(int i=0;i<n;i++)
            {
                /* if we are using dp[j-coins[i]] then we have to add current i coin so add 1*/
                if(coins[i] <= j)
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
            //cout<<j<<" "<<dp[j]<<endl;
        }
        //cout<<INT_MAX<<endl;
        return (dp[amount] == INT_MAX-1)? -1: dp[amount];
        
    }
};
