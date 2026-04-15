class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj, vector<bool> &vis, int i)
    {
        vis[i] = true;

        for(auto &n:adj[i])
        {
            if(vis[n] == false)
                dfs(adj,vis,n);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) 
    {

        unordered_map<int,vector<int>> adj;
        vector<bool> vis(n, false);
        for(auto &i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i] == false)
            {
                dfs(adj, vis,i);
                ans++;
            }
        }
        return ans;
    }
};
