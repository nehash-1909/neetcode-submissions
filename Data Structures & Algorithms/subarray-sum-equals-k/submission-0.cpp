class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> pre(n+1,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            pre[i+1] = nums[i] + pre[i];
        }
     
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pre[i] - pre[j] == k)
                    ans++;
            }
        }

        return ans;
        
    }
};