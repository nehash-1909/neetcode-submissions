class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int ans = -1;
        int n = heights.size();
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++)
        {
            int start = i;
            while(!st.empty() && st.top().second> heights[i])
            {
                int area = st.top().second*(i-st.top().first); 
                ans = max(ans, area);
                cout<<"poping "<<st.top().second<<"area "<<area<<endl;
                /* how much far it can go on left */
                start = st.top().first;
                st.pop();
            }
            cout<<"pushing h:"<<heights[i]<<"width: "<<start<<endl;
            st.push({start, heights[i]});
        }
        while(!st.empty())
        {
            int h = st.top().second;
            int w = st.top().first;
            int area = h*(n-w);
            cout<<"poping "<<h<<"width: "<<w<<"area "<<area<<endl;
            ans = max(ans, area);
            st.pop();
        }
        return ans;
        
    }
};
