class Solution {
public:
    #if 0
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
    #endif
    class TrieNode
    {
        public:
        unordered_map<char, TrieNode*> children;
        bool is_word = false;
    };

    class Trie
    {
    public:
        TrieNode* root;

        Trie()
        {
            root = new TrieNode();
        }

        void insert(string word)
        {
            TrieNode* node = root;
            for(auto c: word)
            {
                if(!node->children.contains(c))
                {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }

        bool find(string s)
        {
            TrieNode* node = root;
            for(auto c: s)
            {
                if(!node->children.contains(c))
                {
                    return false;
                }
                node = node->children[c];
            }

            return node->is_word;
        }
    };
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        Trie trie;

        for (string word : wordDict) {
            trie.insert(word);
        }

        vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            string ans = "";
            for(int j=i;j<s.size(); j++)
            {
                ans += s[j];
                if(trie.find(ans))
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
