class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(auto s: strs)
        {
            string b = s;
            sort(b.begin(), b.end());
            cout<<b<<" "<<s<<endl;
            m[b].push_back(s);
        }

        for(auto s: m)
        {
            ans.push_back(s.second);
        }

        return ans;
        
    }
};
