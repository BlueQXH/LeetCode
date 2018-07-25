class Solution {
public:
    string reverseWords(string s) {
        size_t i = 0;
        while (i < s.size()) {
            size_t j = i;
            while (s[j] != ' ' && j < s.size())
                ++j;
            size_t mid = (j-i+1)/2, k = j-1;
            for (; mid != 0; ++i, --k, --mid)
                swap(s[i], s[k]);
            i = j+1;
        }
        return s;
    }
};
