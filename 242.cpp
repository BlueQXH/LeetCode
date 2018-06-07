class Solution1 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else
            return false;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, size_t> s_cnt, t_cnt;
        string::const_iterator i, j;
        for (i = s.cbegin(), j = t.cbegin(); i != s.cend() && j != t.cend(); ++i, ++j) {
            if (s_cnt.find(*i) == s_cnt.cend())
                s_cnt.insert(make_pair(*i, 1));
            else
                ++s_cnt[*i];
            if (t_cnt.find(*j) == t_cnt.cend())
                t_cnt.insert(make_pair(*j, 1));
            else
                ++t_cnt[*j];
        }
        for (i = s.cbegin(); i != s.cend(); ++i)
            if (s_cnt[*i] != t_cnt[*i])
                return false;
        return true;
    }
};
