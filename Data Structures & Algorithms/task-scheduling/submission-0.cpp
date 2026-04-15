class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int arr[26] = {0};

        for(auto t:tasks)
        {
            arr[t-'A']++;
        }
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(int i=0;i<26;i++)
        {
            if(arr[i] > 0)
                pq.push(arr[i]);
        }
        int time = 0;
        while(!pq.empty() || !q.empty())
        {
            time++;
            if(!pq.empty())
            {
                int element = pq.top();
                pq.pop();

                if(element > 1)
                    q.push({element-1, time+n});
            }
            if(!q.empty() && q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
            
        }

        return time;
        
    }
};
