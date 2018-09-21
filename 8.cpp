class Solution {
public:
    int change (string &s) {
        long long num = 0;
        int index = 0;
        int flag = minus ? -1 : 1;
        while (index < s.size()) {
            num = 10*num + flag*(s[index]-'0');
            ++index;
            if (!minus && num > 0x7FFFFFFF)
                return INT_MAX;
            if (minus && num < (signed int)0x80000000)
                return INT_MIN;
        }
        return num;
    }

    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int index1 = 0;
        while (index1 < str.size() && isblank(str[index1]))
            ++index1;
        if (index1 == str.size() || ((!isdigit(str[index1])) && str[index1] != '+' && str[index1] != '-'))
            return 0;
        if (str[index1] == '+')
            ++index1;
        else if (str[index1] == '-') {
            minus = true;
            ++index1;
        }
        int index2 = index1;
        while (index2 < str.size() && isdigit(str[index2]))
                ++index2;
        string digit(str.substr(index1, index2-index1));
        return change(digit);
    }
private:
    bool minus = false;
};
