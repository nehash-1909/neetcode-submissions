class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();

        for(int i=0;i<row;i++)
        {
            set<char> s;
            for(int j=0;j<col;j++)
            {
                if(s.contains(board[i][j]))
                {
                    cout<<i<<" row "<<j<<endl;
                    return false;
                }
                if(board[i][j] != '.')
                    s.insert(board[i][j]);
            }
        }

        for(int i=0;i<col;i++)
        {
            set<char> s;
            for(int j=0;j<row;j++)
            {
                if(s.contains(board[j][i]))
                {
                    cout<<j<<" col "<<i<<endl;
                    return false;
                }
                if(board[j][i] != '.')
                    s.insert(board[j][i]);
            }
        }

        for(int k=0;k<9;k++)
        {
            set<char> s;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    int row1 = (k/3)*3+i;
                    int col1 = (k%3)*3+j;

                    if(s.contains(board[row1][col1]))
                    {
                        cout<<j<<" col "<<i<<endl;
                        return false;
                    }
                    if(board[row1][col1] != '.')
                        s.insert(board[row1][col1]);
                    
                }
            }
        }
        

        return true;
        
    }
};
