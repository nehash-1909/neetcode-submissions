class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    stack<int> temp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        // 0 1 2
        // 0 --> 1 --> 
        while(!min_st.empty() && val > min_st.top())
        {
            temp.push(min_st.top());
            min_st.pop();
        }
        min_st.push(val);
        while(!temp.empty())
        { 
            min_st.push(temp.top());
            temp.pop();
        }
    }
    
    void pop() {
        int val = st.top();
        st.pop();

        while(!min_st.empty() && val != min_st.top())
        {
            temp.push(min_st.top());
            min_st.pop();
        }
        if(!min_st.empty())
            min_st.pop();
        while(!temp.empty())
        { 
            min_st.push(temp.top());
            temp.pop();
        }

        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {

        return min_st.top();
        
    }
};
