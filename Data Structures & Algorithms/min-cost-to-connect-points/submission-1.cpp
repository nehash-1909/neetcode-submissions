class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {

        unordered_map<int,vector<pair<int,int>>> adj;
        int n = points.size();
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }

        int ans = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> vis(n, false);
        q.push({0,0});

        while(!q.empty())
        {
            auto [d, src] = q.top();
            q.pop();

            //cout<<src<<" "<<d<<endl;
            if(vis[src]) continue;
            vis[src] = true;
            
            ans += d;
            for(auto [nei,dis]: adj[src])
            {
                if(vis[nei] == false)
                {
                    q.push({dis, nei});
                }
            }
        }

        return ans;

        
        
    }
};
