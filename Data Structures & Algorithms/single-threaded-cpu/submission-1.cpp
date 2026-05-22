class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {

        int n = tasks.size();

        for(int i=0; i<n; i++)
        {
            tasks[i].push_back(i);
        }
        // sort in
        sort(tasks.begin(), tasks.end());
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> minHeap;
        vector<int> res;

        int cur_time = tasks[0][0];
        int i = 0;
        while(!minHeap.empty() || i<n)
        {
            while(i<n && cur_time >=  tasks[i][0])
            {
                minHeap.push({tasks[i][1],tasks[i][2] });
                i++;
            }
            if(!minHeap.empty())
            {
                auto [time, index] = minHeap.top();
                minHeap.pop();
                cur_time += time;
                res.push_back(index);
            }
            else
            {
                // we see a time gap so get the nextx execution task
                cur_time = tasks[i][0];
            }

        }

        return res;


    }
};