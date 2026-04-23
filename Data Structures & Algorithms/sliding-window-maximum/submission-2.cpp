class Solution {
public:
    int getMaxVal(vector<int>& nums)
    {
        int maxVal = 0;
        for(int i = 0;i<nums.size();i++)
        {
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;

        for(int i=0;i<=nums.size()-k;i++)
        {
            int maxVal = nums[i];
            for(int j=i;j<i+k;j++)
            {
                maxVal = max(maxVal, nums[j]);
            }
            res.push_back(maxVal);
        }

        return res;
        
    }
};
