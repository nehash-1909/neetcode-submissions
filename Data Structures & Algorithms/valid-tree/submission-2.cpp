class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {

        unordered_map<int, vector<int>> neighbour;

        for(auto &i:edges)
        {
            neighbour[i[0]].push_back(i[1]);
            neighbour[i[1]].push_back(i[0]);
        }

        queue<pair<int,int>> q;
        set<int> s;
        q.push({0,-1});
        s.insert(0);

        while(!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();

            for(auto &n:neighbour[node])
            {
                if(n == parent)
                    continue;
                if(s.contains(n))
                    return false;
                q.push({n, node});
                s.insert(n);   
            }
        }

        return (s.size() == n);

    }
};
