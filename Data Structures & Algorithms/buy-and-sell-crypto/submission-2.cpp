class Solution {
public:
#if 0
int maxProfit(vector<int>& prices) 
{
    int l = 0;
    int r = 1;
    int ans = 0;
    while(r<prices.size())
    {
        if(prices[r] - prices[l] > 0)
        {
            int p = prices[r] - prices[l];
            ans = max(ans, p);
        }
        else
        {
            //found cheep price as r < l
            l = r;
        }
        r++;
    }

    return ans;
}
#endif
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        

        int minB =prices[0];
        int maxP = 0;
        for(int i=1;i<n;i++)
        {
            maxP = max(maxP, prices[i]-minB);
            minB = min(minB, prices[i]);
        }
        return maxP;
        
    }
};
