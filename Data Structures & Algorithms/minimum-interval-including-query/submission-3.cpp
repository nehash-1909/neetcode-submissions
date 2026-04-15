class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        sort(intervals.begin(), intervals.end());
        int m = queries.size();
        vector<pair<int,int>> q;

        for(int i=0;i<m;i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int n = intervals.size();
        
        vector<int> ans(m, -1);
        int j = 0;
        for(int i=0;i<m;i++)
        {
            
            while(j < n && intervals[j][0] <= q[i].first)
            {
                minHeap.push({intervals[j][1]- intervals[j][0] +1, intervals[j][1]});
                j++;
            }
            while(!minHeap.empty() && minHeap.top().second < q[i].first)
            {
                minHeap.pop();
            }
            if(!minHeap.empty())
                ans[q[i].second] = minHeap.top().first;

        }

        return ans;
    }
};
