class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        unordered_map<int,int> hash;

        int n = intervals.size();
        for(int i =0 ;i < n ;i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int len = end - start + 1;

            for(int j = start; j<=end ; j++)
            {
                if(hash.contains(j))
                {
                    hash[j] = min(hash[j], len);
                    //cout<<start<<" "<<hash[start]<<endl;
                }
                else
                {
                    hash[j] = len;
                
                }
            }
            
        }
        int m = queries.size();
        vector<int> ans(m, -1);
        for(int i=0;i<m;i++)
        {

            if(hash.contains(queries[i]))
            {
                cout<<queries[i]<<" "<<hash[queries[i]]<<endl;
                ans[i] = hash[queries[i]];
            }

        }
        return ans;
    }
};
