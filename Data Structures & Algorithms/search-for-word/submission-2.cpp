class Solution {
public:
    void searchWord(bool &res,vector<vector<char>>& board, string &word, int idx, string &ans, int n, int m)
    {
        if(idx == word.size())
        {
            res = true;
            return;
        }

        //cout<<n<<" "<<m<<endl;
        if(n < 0 || m < 0 || n >= board.size() || m >= board[0].size()||board[n][m] != word[idx])
            return;

        
        ans += board[n][m];
        char temp = board[n][m];
        board[n][m] = '#';
        searchWord(res,board,word, idx+1, ans, n+1,m);
        searchWord(res,board,word, idx+1, ans,n-1,m);
        searchWord(res,board,word, idx+1, ans,n, m-1);
        searchWord(res,board,word, idx+1, ans,n, m+1);
        board[n][m] = temp;
        ans.pop_back();
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        string ans = "";
        bool res = false;
        //searchWord(res,board,word, 0, ans,0, 0);
        for(int i = 0; i < board.size(); i++) 
        {
            for(int j = 0; j < board[0].size(); j++) 
            {
               searchWord(res, board, word, 0, ans, i, j);
                if(res)
                    return true;
            }
        }
        return res;
    }
};
