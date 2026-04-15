class Solution {
public:
    void generateS(vector<int>& nums,vector<int>& ans, int idx, vector<vector<int>> &res)
    {
        if(idx == nums.size())
        {
            res.push_back(ans);
            cout<<ans.size()<<" "<<nums.size()<<endl;
            return;
        }
        //add the element
        ans.push_back(nums[idx]);
        generateS(nums,ans,idx+1, res);
        //remove the element
        ans.pop_back();
        generateS(nums,ans,idx+1, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> ans = {};
        vector<vector<int>> res;
        generateS(nums,ans, 0, res);
        return res;
    }
};
