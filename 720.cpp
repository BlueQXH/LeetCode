class Solution {
public:
    static bool myCompare(string &a, string &b) {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() > b.size();
    }
    string longestWord(vector<string>& words) {
        unordered_set<string> str_set;
        for (string &s : words)
            str_set.insert(s);
        sort(words.begin(), words.end(), myCompare);
        for (string &s : words) {
            size_t n = s.size() - 1;
            for (; n > 0; --n)
                if (str_set.find(s.substr(0, n)) == str_set.end())
                    break;
            if (n == 0)
                return s;
        }
        return "";
    }
};
