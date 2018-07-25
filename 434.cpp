class Solution {
public:
    int countSegments(string s) {
        if (s.empty())
            return 0;
        int result = 0;
        int i = 0, j = s.size()-1;
        while (i < s.size() && isblank(s[i]))
            ++i;
        if (i == s.size())
            return 0;
        while (j >= 0 && isblank(s[j]))
            --j;
        if (i == j)
            return 1;
        bool isOK = true;
        for (int k = i; k < j; ++k) {
            if (!isblank(s[k])) {
                isOK = true;
                continue;
            }
            else {
                if (isOK) {
                    ++result;
                    isOK = false;
                }
            }
        }
        ++result;
        return result;
    }
};
