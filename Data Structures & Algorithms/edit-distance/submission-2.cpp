class Solution {
public:
    int compare(vector<vector<int>> &dp, string &word1, string &word2, int idx1, int idx2)
    {
        // "a"
        // abc
        if(idx1 == word1.size())
            return word2.size()-idx2;//Remaining char
        if(idx2 == word2.size())
            return word1.size()-idx1;//Remaining char
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(word1[idx1] == word2[idx2])
            dp[idx1][idx2] = compare(dp,word1, word2, idx1+1, idx2+1);
        else
        {
        int insert_char = compare(dp,word1, word2, idx1+1, idx2);
        int delete_char = compare(dp, word1, word2, idx1, idx2+1);
        int replace_char = compare(dp, word1, word2, idx1+1, idx2+1);

        dp[idx1][idx2] = min({insert_char, delete_char, replace_char})+1;
        }
        return dp[idx1][idx2];
    }
    int minDistance(string word1, string word2) 
    {

        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1, -1) );

        for(int i=0;i<=n;i++)
        {
            dp[i][word2.size()] = word1.size() - i;
        }

        for(int i=0;i<=m;i++)
        {
            dp[word1.size()][i] = word2.size() - i;
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(word1[i] == word2[j])
                dp[i][j] = dp[i+1][j+1];
                else
                dp[i][j] = 1+min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
            }
        }


        return dp[0][0];




        //return compare(dp, word1, word2, 0, 0);
        
    }
};
