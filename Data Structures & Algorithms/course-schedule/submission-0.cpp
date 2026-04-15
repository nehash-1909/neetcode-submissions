class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int r = prerequisites.size();
        int c = prerequisites[0].size();
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> m;

        for(auto &course:prerequisites)
        {
            m[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        int courses = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            courses++;

            for(auto &neighbours:m[node])
            {  
                indegree[neighbours]--;

                if(indegree[neighbours] == 0)
                    q.push(neighbours);
            }
        }
        //cout<<courses<<" ";
        return (courses == numCourses);
        
    }
};
