class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 0;

        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());

        stack<double> st;

        for(int i=0;i<n;i++)
        {
            double time = (double)(target-pair[i].first)/pair[i].second;  
            if(st.empty() || time > st.top())
                st.push(time);
        }

        return st.size();


        
    }
};
