class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {

        int n = coins.size();
        vector<int> dp(amount+1, 0);

        // for(int i=0;i<n;i++)
        // {
        //     dp[coins[i]] = 1;
        // }
        dp[0] = 1;

        // 1 2 3 4
        // 1 -> 1
        // 2 -> 1+1, 2 => 2
        // 3 -> 1+1+1, 1+2, 3 => 3
        // 4 -> 1+1+1+1, 1+1+2, 2+1,1+3

        for(int i=0;i<n;i++)
        {
            for(int j=coins[i];j<=amount;j++)
            {
                
                    dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
        
    }
};
