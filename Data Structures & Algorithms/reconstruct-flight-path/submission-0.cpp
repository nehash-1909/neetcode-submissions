class Solution {
public:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &adj, vector<string> &res, string port)
    {
        auto &q = adj[port];
        while(!q.empty())
        {
            string next_stop = q.top();
            q.pop();
            dfs(adj,res,next_stop);
        }
        res.push_back(port);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {

        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto &tic:tickets)
        {
            adj[tic[0]].push(tic[1]);
        }

        vector<string> res;
        dfs(adj,res, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
