class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        if (pushed.size() != popped.size())
        {
            return false;
        }
        
        stack<int> st;
        vector<int>::size_type popped_index = 0;
        for (vector<int>::size_type i = 0; i < pushed.size(); ++i)
        {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[popped_index])
            {
                st.pop();
                ++popped_index;
            }
        }
        return st.empty();
    }
};
