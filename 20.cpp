class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        else if (s.size()%2 != 0)
            return false;
        stack<char> c;
        for (char &ch : s) {
            if (ch == '(' || ch == '[' || ch == '{')
                c.push(ch);
            else if (c.empty())
                return false;
            else if (ch == ')') {
                if (c.top() != '(')
                    return false;
                else
                    c.pop();
            }
            else if (ch == ']') {
                if (c.top() != '[')
                    return false;
                else
                    c.pop();
            }
            else if (ch == '}') {
                if (c.top() != '{')
                    return false;
                c.pop();
            }
        }
        return c.empty();
    }
};
