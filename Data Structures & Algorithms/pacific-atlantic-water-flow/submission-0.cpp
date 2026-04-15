class Solution {
public:
    int dis[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& heights, int i, int j, int n, int m, vector<vector<bool>> &vis)
    {

        vis[i][j] = true;
        for(auto d:dis)
        {
            int r = i+d[0];
            int c = j+d[1];
            // doing DFS starting from each cell toward oceans heights[r][c] >= heights[i][j]
            if(r>=0 && c >=0 && r<n && c<m && heights[r][c] >= heights[i][j] && !vis[r][c])
            {
                dfs(heights, r,c,n,m, vis);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        for(int i=0;i<n;i++)
        {
            dfs(heights,i,0, n,m, pac);
        }

        for(int i=0;i<m;i++)
        {
            dfs(heights,0,i, n,m, pac);
        }

        for(int i=0;i<n;i++)
        {
            dfs(heights,i,m-1, n,m, atl);
        }

        for(int i=0;i<m;i++)
        {
            dfs(heights,n-1,i, n,m, atl);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }

        return res;

        
    }
};
