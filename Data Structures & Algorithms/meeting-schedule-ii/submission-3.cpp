/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compareElements(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first)
            return a.second > b.second; 
        return a.first < b.first;
    }
    int minMeetingRooms(vector<Interval>& intervals) {

        //calculate number of overlap
        int n = intervals.size();
        //sort(intervals.begin(), intervals.end(),compareElements);
        vector<pair<int,int>> timeline;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            int start = intervals[i].start;
            int end = intervals[i].end;
            timeline.push_back({start, 0});
            timeline.push_back({end, 1});
        }
        sort(timeline.begin(), timeline.end(),compareElements);
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(timeline[i].second == 0)
            {
                count++;
            }
            else
            {
                count--;
            }

            ans = max(count,ans);
        }

        return ans;
    }
};
