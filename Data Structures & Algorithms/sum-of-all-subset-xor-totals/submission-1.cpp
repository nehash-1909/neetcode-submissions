class Solution {
public:
    int dfs(vector<int>& nums, int total, int i) 
    {
        if(i == nums.size())
            return total;
        
        return dfs(nums,total^nums[i], i+1) + dfs(nums,total, i+1);
    }
    int subsetXORSum(vector<int>& nums) 
    {

        return dfs(nums, 0,0);
        
    }
};