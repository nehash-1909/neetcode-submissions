class Solution {
public:
    bool isRegex(string s, int idx1, string p, int idx2, vector<vector<int>> &dp)
    {

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if(idx1 >= s.size() && idx2 >= p.size())
            return true;
        if(idx2 >= p.size())
            return false;
        

        bool isMatching =((idx1 < s.size())&& ((s[idx1] == p[idx2])||(p[idx2] == '.')));
        // aab
        // c*a*b
        if(((idx2+1) < p.size()) && (p[idx2+1] == '*'))
        {
            // choose prev char // not choose prev char
            dp[idx1][idx2] = (isMatching && isRegex(s,idx1+1,p, idx2, dp)) || (isRegex(s,idx1,p,idx2+2, dp));
            
            return dp[idx1][idx2];
        }

        if(isMatching)
        {
            dp[idx1][idx2] = isRegex(s,idx1+1,p, idx2+1, dp);
            return dp[idx1][idx2];
        }
        return false;

    }
    bool isMatch(string s, string p) {

        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));

        return isRegex(s,0,p,0, dp);
        
    }
};
