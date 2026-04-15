class Solution {
public:
    void backtracking(vector<int>& nums, set<vector<int>> &res, vector<int>& ans, int idx)
    {
        if(idx >= nums.size())
        {
            res.insert(ans);
            return;
        }

        ans.push_back(nums[idx]);
        backtracking(nums,res,ans,idx+1);

        ans.pop_back();
        backtracking(nums,res,ans,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        backtracking(nums,res,ans,0);
        vector<vector<int>> final(res.begin(), res.end());
        return final;
    }
};
