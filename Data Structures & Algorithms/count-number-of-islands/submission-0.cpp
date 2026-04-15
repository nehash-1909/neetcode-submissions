class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void checkIsland(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m || i<0 || j<0 ||grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        for (int k = 0; k < 4; k++) 
        {
            checkIsland(grid, i+ directions[k][0], j+ directions[k][1], vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int island = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    checkIsland(grid, i, j, vis);
                    island++;
                }
            }
        }
        return island;
        
    }
};
