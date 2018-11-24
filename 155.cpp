class MinStack1
{
public:
    void push(int x)
	{
        data_st.push(x);
        if (data_st.empty() || x < min_st.top())
		{
            min_st.push(x);
		}
        else
		{
            min_st.push(min_st.top());
		}
    }
    
    void pop()
	{
        if (data_st.empty())
		{
            return ;
		}
        data_st.pop();
        min_st.pop();
    }
    
    int top()
	{
        return data_st.top();
    }
    
    int getMin()
	{
        return min_st.top();
    }
private:
    stack<int> min_st; //辅助栈
    stack<int> data_st;
};

class MinStack2
{
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x)
    {
        if (!st.empty())
        {
            int val = st.top().second;
            if (val < x)
            {
                st.push(make_pair(x, val));
                return ;
            }
        }
        st.push(make_pair(x, x));
    }
    
    void pop()
    {
        st.pop();
    }
    
    int top()
    {
        return st.top().first;
    }
    
    int getMin()
    {
        return st.top().second;
    }
private:
    stack<pair<int, int>> st;
};

class MinStack3
{
public:
    /** initialize your data structure here. */
    MinStack(){}
    
    void push(int x)
    {
        if (st.empty())
        {
            st.push(0);
            Min = x;
        }
        else
        {
            st.push(x-Min);
            if (x < Min)
            {
                Min = x;
            }
        }
    }
    
    void pop()
    {
        if (st.top() < 0)
        {
            Min -= st.top();
        }
        st.pop();
    }
    
    int top()
    {
        return st.top() < 0 ? Min : st.top()+Min;
    }
    
    int getMin()
    {
        return Min;
    }
private:
    stack<int> st;
    int Min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
