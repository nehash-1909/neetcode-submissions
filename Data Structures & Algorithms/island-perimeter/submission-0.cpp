class Solution {
public:
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        // Water → contributes to perimeter
        if(i<0 || j<0 || i >= grid.size() || j>= grid[0].size() || grid[i][j] == 0)
            return 1;

        // Already visited → no contribution
        if(grid[i][j] == -1)
            return 0;

        grid[i][j] = -1;
        int total = 0;
        for(auto d:dir)
        {
            int r = d[0];
            int c = d[1];
            total += dfs(grid,i+r, j+c);
        }
        return total;

    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    return dfs(grid, i, j);
            }
        }
        return 0;
    }
};