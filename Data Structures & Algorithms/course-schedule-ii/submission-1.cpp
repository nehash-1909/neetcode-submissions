class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {

        vector<int> indegree(numCourses, 0);
        vector<int> res;
        int covered = 0;

        //[a->b] : b first
        unordered_map<int, vector<int>> adj_mat;

        for(auto &i:prerequisites)
        {
            adj_mat[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto &n:adj_mat[node])
            {
                indegree[n]--;
                if(indegree[n] == 0)
                {
                    q.push(n);
                    res.push_back(n);
                }
            }
            covered++;
        }
        if(covered == numCourses)
            return res;
        return {};

        
    }
};
