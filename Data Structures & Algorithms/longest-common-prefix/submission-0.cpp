class TrieNode
{
    public:
        unordered_map<char, TrieNode*> children;
};
TrieNode* root;
class Trie
{
    public:
    
    Trie()
    {
        root = new TrieNode;
    }

    void add_string(string s)
    {
        TrieNode* temp = root;
        for(char c: s)
        {
            if(!temp->children.contains(c))
            {
                temp->children[c] = new TrieNode();
            }
            temp = temp->children[c];
        }
    }


};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string min_str = "";
        int min_len = INT_MAX;
         Trie trie;
        for(auto s: strs)
        {
            trie.add_string(s);
            if(s.size()<min_len)
            {
                min_len = s.size();
                min_str = s;
            }
        }


        
        for(auto s: strs)
        {
            if(min_str == s)
                continue;

            TrieNode* node = root;
            int i = 0;
            while(i < s.size() && i<min_str.size())
            {
                if(s[i] == min_str[i] && node->children.contains(s[i]))
                {
                    
                    node = node->children[s[i]];
                    i++;
                }
                else
                {
                    if(i < min_str.size())
                        min_str = min_str.substr(0, i);
                    break;
                }
            }
            
        }
        return min_str;
        
    }
};