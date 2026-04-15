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

        // monkeys
        // money
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m, -1) );
        return compare(dp, word1, word2, 0, 0);
        
    }
};
