class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int maxVal = -1;
        int minVal = 0;
        int totalSum = 0;
        int gmaxVal = -1;
        int gminVal = 0;
        for(auto n:nums)
        {
            maxVal = max(n, maxVal+n);
            minVal = min(n, minVal+n);
            totalSum += n;
            gmaxVal = max(gmaxVal, maxVal);
            gminVal = min(gminVal, minVal);

        }

        return gmaxVal>0?max(gmaxVal, totalSum-gminVal): gmaxVal;
        
    }
};