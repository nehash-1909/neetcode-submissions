class Solution {
public:
    void backtracking(vector<int>& nums, vector<int>& ans, vector<vector<int>> &res, vector<bool> &should_include)
    {

        if(ans.size() == nums.size())
        {
            res.push_back(ans);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!should_include[i])
            {
                ans.push_back(nums[i]);
                should_include[i] = true;
                backtracking(nums, ans, res, should_include);
    
                ans.pop_back();
                should_include[i] = false;
            }
        }

        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        vector<bool> should_include(nums.size(), false);
        backtracking(nums, ans, res, should_include);
        return res;
    }
};
