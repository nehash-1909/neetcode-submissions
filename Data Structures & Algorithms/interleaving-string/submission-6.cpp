class Solution {
public:
    bool isPossible(string &s1, int idx1, string &s2, int idx2, string &s3,int idx3) 
    {
        if (idx3 == s3.length()) {
            return (idx1 == s1.length()) && (idx2 == s2.length());
        }

        if(s1[idx1] == s3[idx3] && s2[idx2] == s3[idx3])
            return isPossible(s1, idx1+1, s2, idx2, s3, idx3+1) || isPossible(s1, idx1, s2, idx2+1, s3, idx3+1);
        else if(s1[idx1] == s3[idx3])
            return isPossible(s1, idx1+1, s2, idx2, s3, idx3+1);
        else if(s2[idx2] == s3[idx3])
            return isPossible(s1, idx1, s2, idx2+1, s3, idx3+1);
        else
            return false;
        

    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        //return isPossible(s1, 0, s2, 0, s3, 0);
        int n = s1.length();
        int m = s2.length();
        if(n+m != s3.size())
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;

        for(int i=s1.length();i>=0;i--)
        {
            for(int j=s2.length();j>=0;j--)
            {
                if(i< n && s1[i] == s3[i+j])
                    dp[i][j] = dp[i][j] || dp[i+1][j];
                if(j < m && s2[j] == s3[i+j])
                    dp[i][j] = dp[i][j] || dp[i][j+1];
            
            }
        }

        return dp[0][0];
        
    }
};
