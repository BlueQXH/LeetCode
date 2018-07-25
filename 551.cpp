class Solution {
public:
    bool checkRecord(string s) {
        size_t i = 0, cnt_A = 0;
        while (i < s.size()) {
            if (s[i] == 'A') {
                ++cnt_A;
                if (cnt_A > 1)
                    return false;
                ++i;
            }
            else if (s[i] == 'L') {
                size_t j = i;
                while (j < s.size() && s[j] == 'L')
                    ++j;
                if (j-i > 2)
                    return false;
                else
                    i = j;
            }
            else
                ++i;
        }
        return true;
    }
};
