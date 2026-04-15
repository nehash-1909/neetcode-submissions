class Solution {
public:
    int numDistinct(string s, int idx1, string t, int idx2, vector<vector<int>> &dp) 
    {

        if(idx2 == t.size())
            return 1;
        if(idx1 == s.size())
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        dp[idx1][idx2] = numDistinct(s, idx1+1, t, idx2, dp);
        if(s[idx1] == t[idx2])
             dp[idx1][idx2] += numDistinct( s,  idx1+1, t, idx2+1, dp);
        
        return dp[idx1][idx2];
        
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.size(), -1));
        if(s.size() < t.size())
            return 0;
        return numDistinct( s,  0, t, 0, dp);
        
    }
};
