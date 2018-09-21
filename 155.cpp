class MinStack {
public:
    void push(int x) {
        data_st.push(x);
        if (data_st.empty() || x < min_st.top())
            min_st.push(x);
        else
            min_st.push(min_st.top());
    }
    
    void pop() {
        if (data_st.empty())
            return ;
        data_st.pop();
        min_st.pop();
    }
    
    int top() {
        return data_st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
private:
    stack<int> min_st; //辅助栈
    stack<int> data_st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
