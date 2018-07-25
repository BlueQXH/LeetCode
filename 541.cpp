class Solution {
public:
    string reverseStr(string s, int k) {
        size_t i = 0;
        while (i < s.size()) {
            if (s.size() - i >= k) {
                size_t mid = k/2, p, q;
                for (p = i, q = i + k - 1; mid != 0; ++p, --q, --mid)
                    swap(s[p], s[q]);
                if (s.size()-i >= 2 * k)
                    i += 2 * k;
                else
                    break;
            }
            else {
                size_t mid = (s.size() - i) / 2, p, q;
                for (p = i, q = s.size() - 1; mid != 0; ++p, --q, --mid)
                    swap(s[p], s[q]);
                break;
            }
        }
        return s;
    }
};
