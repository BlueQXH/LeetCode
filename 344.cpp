class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size()-1, mid = s.size()/2;
        for (i = 0; mid != 0; ++i, --j, --mid)
            swap(s[i], s[j]);
        return s;
    }
};
