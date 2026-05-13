class Solution {
public:
    string decodeString(string s) 
    {

        stack<string> st;
        string ans = "";
        /*
            st : 2 a b b b
            ans : bbb
        */
        for(auto c:s)
        {
            if(c != ']')
                st.push(string(1, c));
            else
            {
                string temp = ""; 
                while(!st.empty() && st.top() != "[")
                {
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop(); // remove "["

                string numStr = "";
                while(!st.empty() && isdigit(st.top()[0]))
                {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int digit = stoi(numStr);

                //st.pop();
                string res = "";
                for(int i=0;i<digit;i++)
                    res += temp;
                st.push(res);
            }
        }
        while(!st.empty())
        {
            ans = st.top()+ans;
            cout<<st.top()<<" ";
            st.pop();
        }
        return ans;
        
    }
};