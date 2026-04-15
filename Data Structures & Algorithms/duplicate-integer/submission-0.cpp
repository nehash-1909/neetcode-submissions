class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> s;

        for(auto i:nums)
        {
            s.insert(i);
        }

        if(s.size() == nums.size())
            return false;
        return true;
        
    }
};