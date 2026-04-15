class Solution {
public:
    int dir[4][2] = {{0,1},{0, -1},{1,0},{-1,0}};
    void markBorder(vector<vector<char>>& board, int i, int j)
    {
        int n = board.size();
        int m = board[0].size();

        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'O')
            return;
        board[i][j] = 'T';
        for(auto d: dir)
        {
            int r = i+d[0];
            int c = j+d[1];
            markBorder(board,r,c);
        }

    }
    void solve(vector<vector<char>>& board) 
    {

        int n = board.size();
        int m = board[0].size();
        /* 1. Mark Border T */
        for(int i=0;i<n;i++)
        {
            markBorder(board, i, 0);
            markBorder(board, i, m-1);
        }
        for(int j=0;j<m;j++)
        {
            markBorder(board, 0, j);
            markBorder(board, n-1, j);
        }
        /* 2. Mark everything else as X */

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        /* 3. Revert boundry regions to O */

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }

    }
};
