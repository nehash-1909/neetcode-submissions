class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> res;
        for(auto i:nums)
        {
            m[i]++;
        }
        vector<pair<int, int>> om; 
        for(auto i:m)
        {
            om.push_back({i.second, i.first});
        }

        sort(om.rbegin(), om.rend());
        for(int j=0;j<k;j++)
        {
            res.push_back(om[j].second);
        }

        return res;

    }
};
