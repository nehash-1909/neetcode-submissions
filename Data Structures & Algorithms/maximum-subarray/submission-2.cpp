class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int res = nums[0];
        for(int i=1;i<n;i++)
        {
            if(ans < 0)
                ans = 0;

            ans += nums[i];
            
            res = max(res,ans);
            //cout<<ans<<" ";
        }
        return res;
    }   
};
