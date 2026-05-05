class Solution {
public:
    int romanToInt(string s) 
    {
        // XLIX
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(i+1 < n && roman[s[i+1]] > roman[s[i]])
                ans -= roman[s[i]];
            else
                ans += roman[s[i]];
        }
        
        return ans;
    }
};