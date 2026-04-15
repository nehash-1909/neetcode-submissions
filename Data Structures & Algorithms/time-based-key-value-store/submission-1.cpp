class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        timeMap[key].emplace_back(timestamp,value);
        
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if(timeMap.contains(key))
        {
            int l = 0;
            int r = timeMap[key].size()-1;

            while(l<=r)
            {
                int m = (l+r)/2;

                if(timeMap[key][m].first <= timestamp)
                {
                    ans = timeMap[key][m].second;
                    l = m+1;
                }
                else
                {
                    r = m-1;
                }
            }
            //return timeMap[key].second;
        }
        return ans;    
    }
};
