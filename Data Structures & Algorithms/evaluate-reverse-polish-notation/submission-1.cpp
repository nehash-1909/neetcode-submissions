class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(auto i: tokens)
        {
            if(i == "+" || i == "-" || i == "*" || i == "/")
            {
                int res;
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                if(i == "+")
                {
                        res = first + second;
                }
                else if(i == "-")
                {
                    res =  second - first;
                }
                else if(i == "*")
                {
                    res = first * second;
                }
                else if( i == "/")
                {
                    res = second/first;
                }
                st.push(res);
            }
            else
            {
                st.push(stoi(i));
            }
        }
        return st.top();
        
    }
};
