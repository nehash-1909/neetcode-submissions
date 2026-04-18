class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        int dis[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
        vector<vector<bool>> vis(n+1, vector<bool>(n+1, false));

        q.push({grid[0][0],0,0});
        while(!q.empty())
        {
            auto [level,x,y] = q.top();
            q.pop();
            if(vis[x][y])
                continue;
            vis[x][y] = true;

            if(x == n-1 && y == n-1)
                return level;

            for(auto &d:dis)
            {
                int n_x = x + d[0];
                int n_y = y + d[1];
                if(n_x< n && n_y< m && n_y >=0 && n_x>=0 && !vis[n_x][n_y])
                {
                    int time = max(level, grid[n_x][n_y]);
                    q.push({time,n_x,n_y});
                }
            }
        }
        return -1;
    }
};
