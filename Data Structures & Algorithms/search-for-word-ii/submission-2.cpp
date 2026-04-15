class Trie
{
    public:
    unordered_map<char, Trie*> children;
    bool end = false;

    void addWord(const string& word) 
    {
        Trie* cur = this;
        for(auto c: word)
        {
            if(!cur->children.contains(c))
            {
                cur->children[c] = new Trie();
            }
            cur = cur->children[c];
        }
        cur->end = true;
    }
};
class Solution {
public:
    void search(vector<vector<char>>& board,Trie* node, int row, int col, vector<vector<bool>> &visited, set<string> &res, string &word)
    {

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()|| !node->children.contains(board[row][col]) || visited[row][col])
            return;

        visited[row][col] = true;
        node = node->children[board[row][col]];
        word += board[row][col];
        if(node->end)
            res.insert(word);
        
        search(board, node, row+1, col, visited, res, word);
        search(board, node,row-1, col, visited, res, word);
        search(board, node,row, col+1, visited, res, word);
        search(board, node,row, col-1, visited, res, word);
        word.pop_back();
        visited[row][col] = false;
        

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>> visited;
        set<string> res;
        string word = "";
        visited.assign(board.size(), vector<bool>(board[0].size(), false));
        Trie* root = new Trie();
        for(auto s: words)
        {
            root->addWord(s);
        }

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                search(board, root, i, j, visited, res, word);   
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
