class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        sort(intervals.begin(), intervals.end());
        //sort(queries.begin(), queries.end());

        int m = queries.size();

        

        int n = intervals.size();
        
        vector<int> ans(m, -1);
        for(int i=0;i<m;i++)
        {
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for(int j=0;j<n;j++)
            {
                if(intervals[j][0] > queries[i])
                    break;
                //cout<<queries[i]<<" "<<intervals[j][0]<<" "<<intervals[j][1]<<endl;
                if(intervals[j][0] <= queries[i] && intervals[j][1] >= queries[i])
                {
                    minHeap.push(intervals[j][1]- intervals[j][0] +1);
                }
                
            }
            if(minHeap.size() > 0)
                ans[i] = minHeap.top();

        }
        return ans;
    }
};
