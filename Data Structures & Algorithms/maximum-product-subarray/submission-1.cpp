class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int pre = 1;
        int suf = 1;
        int res = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            pre = (nums[i]*(pre==0?1:pre));
            suf = nums[n-i-1]*(suf==0?1:suf);
            res = max({res,pre, suf});
        }
        return res;
    }
};
