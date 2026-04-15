class Solution {
public:
    void backTrack(vector<int>& nums, vector<vector<int>> &res, vector<int> &ans, int idx, int arraySum, int target)
    {
        //base
        if(arraySum == target)
        {
            res.push_back(ans);
            return;
        }
        if(idx == nums.size() || arraySum > target)
        {
            return;
        }

        //push
        arraySum += nums[idx];
        ans.push_back(nums[idx]);
        backTrack(nums, res, ans, idx, arraySum, target);

        //pop
        arraySum -= nums[idx];
        ans.pop_back();
        backTrack(nums, res, ans, idx+1, arraySum, target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {

        vector<vector<int>> res;
        vector<int> ans;
        backTrack(nums, res, ans, 0, 0, target);

        return res;
        
    }
};
