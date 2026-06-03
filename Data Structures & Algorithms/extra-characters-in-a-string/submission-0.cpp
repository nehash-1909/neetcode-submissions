class TrieNode
{
    public:
    unordered_map<char, TrieNode*> children;
    bool end = false;
};
class Trie
{
    public:
    TrieNode *root;
    Trie() 
    {
        root = new TrieNode();   
    }
    void insertTrie(string s)
    {
        TrieNode* cur = root;
        for(auto c:s)
        {
            if(!cur->children.contains(c))
            {
                cur->children[c] = new TrieNode(); 
            }
            cur = cur->children[c];
        }
        cur->end = true;
    }
};
class Solution {
public:
    int dfs(int i, vector<int> &dp, string& s, Trie& trie)
    {
        if(i >= s.size())
            return 0;
        if(dp[i] != INT_MAX)
            return dp[i];
         // Option 1: treat s[i] as an extra character
        dp[i] = 1 + dfs(i+1,dp,s,trie);

        //check next substr
        TrieNode* cur = trie.root;
         // Option 2: match dictionary words starting at i
        for(int j=i;j<s.size();j++)
        {
            if(!cur->children.contains(s[j]))
                break;
            
            cur = cur->children[s[j]];
            if(cur->end)
                dp[i] = min(dp[i], dfs(j+1,dp,s,trie));
        }
        return dp[i];
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        Trie trie;
        for(auto str: dictionary)
        {
            trie.insertTrie(str);
        }
        
        vector<int> dp(s.size()+1, INT_MAX);
        int res = dfs(0,dp,s,trie);

        return res;
        
    }
};