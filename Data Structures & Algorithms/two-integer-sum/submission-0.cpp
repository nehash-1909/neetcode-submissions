class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {

        int n = nums.size();
        vector<int> res(2,0);
        unordered_map<int,int> m;

        for(int i=0;i<n;i++)
        {
            if(m.contains(target-nums[i]))
            {
                res[0] = m[target-nums[i]];
                res[1] = i;
            }
            else
            {
                m[nums[i]] = i;
            }
        }

        return res;
        
    }
};
