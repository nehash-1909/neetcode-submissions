class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        int n = s.size();
        stack<char> st;
        while(s[i])
        {
            if(s[i] == ')')
            {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                return false;
            }
            else if(s[i] == '}')
            {
                if( !st.empty() && st.top() == '{')
                    st.pop();
                else
                return false;
            }
            else if(s[i] == ']')
            {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                return false;
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }

        return st.empty();
        
    }
};
