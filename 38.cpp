class Solution {
public:
    string countS(string &s) {
        string result;
        int cnt = 1, i = 0;
        while (i < s.size()) {
            int j = i+1;
            while (j < s.size() && s[j] == s[i]) {
                ++cnt;
                ++j;
            }
            result = result + to_string(cnt) + s[i];
            i = j;
            cnt = 1;
        }
        return result;
    }
    string countAndSay(int n) {
        string result = "1";
        if (n == 1)
            return "1";
        for (int i = 1; i < n; ++i)
            result = countS(result);
        return result;
    }
};
