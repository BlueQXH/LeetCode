class Solution {
public:
    bool isPalindrome (string &s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            else
                ++i, --j;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int i = 0, j = 0, maxSize = 0;
        string result;
        for (i = 0; i < s.size(); ++i) {
            for (j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    string tmp = s.substr(i, (j-i+1));
                    if (isPalindrome(tmp) && maxSize < j-i+1) {
                        maxSize = j-i+1;
                        result = tmp;
                    }
                }
            }
        }
        return result;
    }
};
