class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0, pre = 0, cur = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1])
                ++cur;
            else {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur)
                ++result;
        }
        return result;
    }
};
