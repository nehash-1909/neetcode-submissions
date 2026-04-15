class Solution {
public:
    bool part(vector<int>& nums, int idx, int target)
    {
        if(idx == nums.size())
            return false;
        
        if(target == 0)
            return true;
        
        return part(nums, idx+1, target-nums[idx]) || part(nums, idx+1, target); 
    }
    bool canPartition(vector<int>& nums) 
    {

        int sum = 0;
        for(int i:nums)
        {
            sum += i;
        }
        if(sum%2 == 1)
            return false;
        return part(nums, 0, sum/2);
       
    }
};
