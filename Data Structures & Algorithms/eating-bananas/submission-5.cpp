class Solution {
public:
    //#if 0
    bool canEat(vector<int>& piles, int h, int k)
    {
        int hr = 0;
        for(auto i: piles)
        {
            hr += (i + k - 1) / k; 
            
        }
        if(hr <= h)
            return true;
        return false;
    }
    //#endif
    int minEatingSpeed(vector<int>& piles, int h) {

        int sum = 0;
        int maxVal = INT_MIN;
        for(auto i: piles)
        {
            
            maxVal = max(maxVal, i);
        }
        
        int l = 1;
        int r = maxVal;

        /*
            k = 1, 10

            k= 1 => 10 hr
            k = 2 => 
        */

        while(l<r)
        {
            
            int m = (l+r)/2;
            //cout<<l<<" "<<m<<" "<<r;
            // int hr = 0;
            // for(auto i: piles)
            // {
            //      hr += (i + m - 1) / m;   // ceil(i/m)
            
            // }
            if(canEat(piles,h,m))
            {
                r = m;
            }
            else
            {
                l = m+1;
            }
        }

        return r;
    }
};
