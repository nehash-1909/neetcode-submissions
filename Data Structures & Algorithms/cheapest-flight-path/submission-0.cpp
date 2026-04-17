class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &f:flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<tuple<int,int,int>> q;
        unordered_map<int, int> distance;

        for(int i=0;i<=n;i++)
        {
            distance[i] = INT_MAX;
        }

        distance[src] = 0;
        q.push({src,0,0});


        while(!q.empty())
        {
            auto [node, d, stops] = q.front();
            q.pop();

            if(stops > k)
                continue;


            for(auto &[nei,dis]:adj[node])
            {
                if(d+dis > distance[nei])
                    continue;
                distance[nei] = d+dis;
                q.push({nei, d+dis, stops+1});
            }
        }

        if(distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
        
    }
};
