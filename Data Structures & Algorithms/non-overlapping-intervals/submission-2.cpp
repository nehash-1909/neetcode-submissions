class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {

        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int n = intervals.size();

        //int i = 0;

        int prevEnd = intervals[0][1];

        for(int i = 1; i<n;i++)
        {
            int start = intervals[i][0];
            int end   = intervals[i][1];

            if(prevEnd > intervals[i][0])
            {
                //overlapping
                ans++;
                prevEnd = min(end, prevEnd);
            }
            else
            {
                // no overlap
                prevEnd = end;
            }   
        }

        return ans;


        
    }
};
