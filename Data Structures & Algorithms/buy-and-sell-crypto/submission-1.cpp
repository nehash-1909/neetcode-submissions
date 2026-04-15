class Solution {
public:
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
#if 0
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minA(n, 0);
        vector<int> maxA(n, 0);

        minA[0] = prices[0];
        maxA[n-1] = prices[n-1];
        for(int i=1;i<n;i++)
        {
            minA[i] = min(minA[i-1],prices[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            maxA[i] = max(maxA[i+1], prices[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans, maxA[i]-minA[i]);
        }
        return ans;
        
    }
#endif
};
