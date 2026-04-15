class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    stack<int> temp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_st.empty())
        {
            min_st.push(val);
        }
        else
        {
            int minVal = min(min_st.top(), val);
            min_st.push(minVal);
        }

        
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {

        return min_st.top();
        
    }
};
