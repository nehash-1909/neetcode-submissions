class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {

        int n = nums.size();
        set<int> s;
        vector<int> ans;
        if(n < 3)
            return nums;

        sort(nums.begin(), nums.end());
        int c = 1;
        for(int i=1;i<n;i++)
        {
            int val = nums[i];
            while(i>0 && nums[i-1] == nums[i])
            {  
                c++;
                i++;
            }
            if(c>n/3)
            {
                ans.push_back(val);
            }
            c = 1;

        }

        return ans;

        
    }
};