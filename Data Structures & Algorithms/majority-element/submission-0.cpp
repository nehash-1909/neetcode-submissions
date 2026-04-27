class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int maxVal = 0;
        int ans = nums[0];
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            int count = 0;
            while(i<n-1 &&nums[i] == nums[i+1])
            {
                count++;
                i++;
            }
            if(maxVal< count)
            {
                maxVal = count;
                if(i > 0)
                    ans = nums[i-1];
            }
            
        }

        return ans;
        
    }
};