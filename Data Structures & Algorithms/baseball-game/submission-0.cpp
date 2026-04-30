class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> st;

        for(int i=0;i<operations.size();i++)
        {
            if(operations[i] == "+")
            {
                int fir = st.top();
                st.pop();
                int sec = st.top();
                st.push(fir);

                st.push(fir+sec);
            }
            else if(operations[i] == "C")
            {
                st.pop();
            }
            else if(operations[i] == "D")
            {
                int num = st.top();
                st.push(num*2);
            }
            else
            {
                st.push(stoi(operations[i]));
            }

        }
        int res = 0;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        return res;
    }
};