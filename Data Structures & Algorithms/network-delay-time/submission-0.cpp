class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &n:times)
        {
            adj[n[0]].push_back({n[1], n[2]});
        }
        
        unordered_map<int, int> dist;
        for(int i=1;i<=n;i++)
        {
            dist[i] = INT_MAX;
        }
        dist[k] = 0;
        queue<pair<int,int>> q;
        q.push({k,0});

        while(!q.empty())
        {
            auto [node,dis] = q.front();
            q.pop();

            if(dist[node] < dis)
                continue;
            for(auto &[nei_node, nei_dis]:adj[node])
            {
                if(dis + nei_dis < dist[nei_node])
                {
                    dist[nei_node] = dis + nei_dis;
                    q.push({nei_node, dis + nei_dis });
                }
            }
        }

        int res = 0;
        for(auto &[node,d]:dist)
        {
            res = max(res, d);
        }

        return (res == INT_MAX ? -1: res);
    }
};
