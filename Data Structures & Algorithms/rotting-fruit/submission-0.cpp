class Solution {
public:
    bool isValid(int i, int j, int n, int m)
    {
        return (i>=0&&j>=0&&i<n&&j<m);
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {

        int n = grid.size();
        int m = grid[0].size();

        int noOnes = 0;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    noOnes++;
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        int dir[4][2] = {{-1,0}, {0,1}, {0, -1}, {1,0}};
        while(!q.empty())
        {
            int size = q.size();
            bool rottenFresh = false; 
            // process all oranges of current minute
            for(int k = 0; k < size; k++) 
            {
                auto [r,c] = q.front();
                q.pop();
                for(auto d:dir)
                {
                    int i = r + d[0];
                    int j = c + d[1];
                    if(isValid(i, j, n, m) && grid[i][j] == 1)
                    {
                        grid[i][j] = 2;
                        noOnes--;
                        q.push({i,j});
                        rottenFresh = true;
                    }
                }
            }
            if(rottenFresh)
                time++;
        }

        return (noOnes?-1:time);
        
    }
};
