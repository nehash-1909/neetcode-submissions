class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {

        vector<int> cap(100001, 0);

        for(auto &t:trips)
        {
            cap[t[1]] +=  t[0];
            cap[t[2]] -=  t[0];
        }
        int curCap = 0;
        for(int i=0;i<100001;i++)
        {
            curCap += cap[i];
            if(curCap > capacity)
                return false;
        }
        return true;
    }
};