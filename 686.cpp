class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string s;
        size_t cnt = 0;
        while (s.size() < B.size()) {
            s.append(A);
            ++cnt;
        }
        if (s.find(B) != -1)
            return cnt;
        s.append(A);
        if (s.find(B) != -1)
            return ++cnt;
        else
            return -1;
    }
};
