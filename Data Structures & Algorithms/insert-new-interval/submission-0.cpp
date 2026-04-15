class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int i = 0;
        while(i<n)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i+1<n && end >= intervals[i+1][0])
            {
                end = max(end,intervals[i+1][1]);
                i++;
            }

            res.push_back({start,end});
            i++;
        }

        return res;
    }
};
