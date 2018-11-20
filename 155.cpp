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

struct element
{
    element(int v) : val(v) {};
    int val = 0;
    int min = 0;
};

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        element e(x);
        if (st.empty())
        {
            e.min = x;
        }
        else
        {
            e.min = x < st.top().min ? x : st.top().min;
        }
        st.push(move(e));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().val;
    }
    
    int getMin() {
        return st.top().min;
    }
private:
    stack<element> st;
};
