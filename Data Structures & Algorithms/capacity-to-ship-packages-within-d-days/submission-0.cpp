class Solution {
public:
    bool isPossible(vector<int>& weights, int maxWeight, int days)
    {

        int n = weights.size();
        int sum = 0;
        int ship = 1;
        for(int i=0;i<n;i++)
        {
            if(sum + weights[i] <= maxWeight)
            {
                sum += weights[i];
            }
            else
            {
                sum = weights[i];
                ship++;
            }
        }

        if(ship <= days)
            return true;
        return false;

    }
    int shipWithinDays(vector<int>& weights, int days) 
    {

        int r = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());

        /*
        l points to the smallest valid capacity
        r points to the largest invalid capacity
        */
        
        while(l<=r)
        {
            int m = (l+r)/2;

            if(isPossible(weights, m, days))
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }

        return l;
    }
};