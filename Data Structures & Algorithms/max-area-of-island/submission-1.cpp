class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int area)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j >=m || grid[i][j]==0)
            return 0;
        grid[i][j] = 0;
        int res = 1;
        for(int k=0;k<4;k++)
        {
            res += dfs(grid, i + directions[k][0], j+directions[k][1], area+1);
        }
        //area = max(res, area);
        return res;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        /*
        0 1 1 0 1
        1 0 1 0 1
        0 1 1 0 1
        0 1 0 0 1
        */
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++)
        {
         for(int j=0;j<m;j++)
         {
           if(grid[i][j] == 1)
           {
                int area = 1;
                res = max(res, dfs(grid, i, j, area));
           }   
         }   
        }

        return res;

    }
};
