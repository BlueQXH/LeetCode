class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s;
        ss.append(s);
        ss.pop_back();
        ss.erase(0, 1);
        return (ss.find(s) == -1) ? false : true;
    }
};
