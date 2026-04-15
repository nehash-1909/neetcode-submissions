class Solution {
public:
    void backtrack(vector<int>& candidates, set<vector<int>> &res, vector<int> &ans, int idx, int sumTarget, int target)
    {
        //base
        if(sumTarget == target)
        {
            //vector<int> temp(ans.begin(), ans.end());
            res.insert(ans);
        }

        if(idx >= candidates.size() || sumTarget > target)
        {
            return;
        }
        //include
        sumTarget += candidates[idx];
        ans.push_back(candidates[idx]);
        backtrack(candidates, res, ans, idx+1, sumTarget, target);
        //exclude
        sumTarget -= candidates[idx];
        ans.pop_back();
        backtrack(candidates, res, ans, idx+1, sumTarget, target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, ans, 0, 0, target);
        vector<vector<int>> final(res.begin(), res.end());
        return final;
    }
};
