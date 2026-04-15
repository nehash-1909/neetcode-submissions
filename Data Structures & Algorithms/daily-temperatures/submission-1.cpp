class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        //30 38 30 36 35 40 28

        stack<pair<int,int>> st;
        vector<int> res;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            int temp = temperatures[i];

            if(st.empty())
            {
                st.push({temp,i});
                res.push_back(0);
            }
            else
            {
                while(!st.empty() && temp >= st.top().first)
                {
                    st.pop();
                }
                if(!st.empty()) 
                {

                    res.push_back(st.top().second-i);
                }
                else
                {
                    res.push_back(0);
                }
                st.push({temp,i});
            }
        }
        reverse(res.begin(), res.end());
        return res;

        
    }
};
