class Trie
{
    public:
    unordered_map<char, Trie*> children;
    bool end = false;
};
class WordDictionary {
public:
    Trie *root;
    WordDictionary() {

        root = new Trie();
        
        
    }
    
    void addWord(string str) {

        Trie* cur = root;
        //reverse(str.begin(), str.end());

        for(auto s: str)
        {
            if(!cur->children.contains(s))
            {
                cur->children[s] = new Trie();
            }

            cur = cur->children[s];
        }

        cur->end = true;
        
    }
    bool dfs(Trie* child, int idx, string &s)
    {
        if(idx == s.size())
            return child->end;

        Trie* cur = child;

        if(s[idx] == '.')
        {
            for(auto &c : cur->children)
            {
                if(dfs(c.second, idx+1, s))
                    return true;
            }
        }
        else
        {
            if(!cur->children.contains(s[idx]))
                return false;
            return dfs(cur->children[s[idx]], idx+1, s);
        }

        return false;
    }
    bool search(string str) {

        return dfs(root, 0, str);

        
        
    }
};
