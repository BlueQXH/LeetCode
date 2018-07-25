class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1, len = 0;
        while (i >= 0 && s[i] == ' ')
            --i;
        int j = i;
        while (j >= 0 && s[j] != ' ') {
            ++len;
            --j;
        }
        return len;
    }
};
