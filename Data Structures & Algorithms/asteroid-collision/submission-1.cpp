class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        vector<int> ans;
        int n = asteroids.size();
        int i = 0;
        while(i < n )
        {
            // (positive)-> <-(negative) only collision case, so 
            if(st.empty() || !(st.top() > 0 && asteroids[i] < 0))
            {
                st.push(asteroids[i]);
                i++;
            }
            else
            {
                // you do NOT need to push asteroids[i] immediately because it is 
                // already the current asteroid being processed.
                if(abs(st.top()) < abs(asteroids[i]))
                {
                    // st.top() destroyed now process asteroids
                    st.pop();
                }
                else if(abs(st.top()) == abs(asteroids[i]))
                {
                    // both destroyed increment asteroids
                    st.pop();
                    i++;
                }
                else
                {
                    // asteroids destroyed increment asteroids
                    i++;
                }
                
            }
            
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};