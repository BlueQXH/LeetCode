class Solution1 {
public:
    static bool cmp (const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.empty())
            return result;
        sort(strs.begin(), strs.end(), cmp);
        for (size_t i = 0; i < strs[0].size(); ++i) {
            for (string &s : strs)
                if (s[i] != strs[0][i])
                    return result;
            result.push_back(strs[0][i]);
        }
        return result;
    }
};

class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.empty())
            return result;
        size_t k = 0;
        while (true) {
            char c = strs[0][k];
            for (string &s : strs)
                if (k >= s.size() || s[k] != c)
                    return result;
            result.push_back(c);
            ++k;
        }
        return result;
    }
};
