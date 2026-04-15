class Solution {
public:
    #if 0
    bool dfs(string &s, int idx, set<string> &hash)
    {
        if(idx == s.size())
            return true;
        string ans = "";
        for(int i=idx;i<s.size();i++)
        {
            ans += s[i];
            if(hash.contains(ans))
            {
                // we can cut from this point
                if(dfs(s,i+1, hash))
                    return true;
            }
                
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {

        set<string> st(wordDict.begin(), wordDict.end());
        st.insert("");
        return dfs(s, 0, st);
    }
    #endif
    bool wordBreak(string s, vector<string>& wordDict) 
    {

        set<string> st(wordDict.begin(), wordDict.end());
        st.insert("");
        vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            string ans = "";
            for(int j=i;j<s.size(); j++)
            {
                ans += s[j];
                if(st.contains(ans))
                {
                    // we can cut from this point
                    dp[i] = dp[i] || dp[j+1];
                }
                if(dp[i]) break; // ✅ optimization
            }
                
        }
        return dp[0];
    }
};
