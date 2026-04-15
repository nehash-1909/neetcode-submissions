class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        for(int i = 0;i<n;)
        {
            
            int start = intervals[i][0];
            int end   = intervals[i][1];
            while(i+1<n && (end >= intervals[i+1][0]))
            {
                /*
                if first point end is less than second point start
                its a overlap
                */

                end = max(end, intervals[i+1][1]);
                i++;

            }

            res.push_back({start,end});
            i++;
        }

        return res;
    }
};
