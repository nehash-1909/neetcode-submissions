class Solution {
public:
    bool isValid(int i, int j, int n, int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                    q.push({i,j});
            }
        }
        int dir[4][2] = {{0,1}, {0,-1}, {1,0},{-1,0}};
        int level = 1;
        while(!q.empty())
        {
            int size = q.size();

            for(int k=0;k<size;k++)
            {
                auto [r,c] = q.front();
                q.pop();
                for(auto d:dir)
                {
                    int i = r + d[0];
                    int j = c + d[1];
                    if(isValid(i, j, n,m) && grid[i][j] == 2147483647)
                    {
                        grid[i][j] = grid[r][c]+1;
                        q.push({i,j});
                    }
                }
            }

        }
        
    }
};
