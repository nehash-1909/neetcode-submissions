class Solution {
public:
    string simplifyPath(string path) 
    {
        string ans = "";
        string s = path + "/";
        stack<string> st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] == '/')
            {
                if(ans == "..")
                {
                    if(!st.empty())
                       st.pop();
                }
                else if((ans != ".") && (ans != ""))
                {
                    st.push(ans);
                }
                ans = "";
            }
            else
            {
                ans += s[i];
            }
        }
        string result = "";

        while(!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result == "" ? "/" : result;  
        
    }
};