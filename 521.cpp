class Solution {
public:
    int findLUSlength(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b)
            return -1;
        else
            return (a.size() < b.size()) ? b.size() : a.size();
    }
};
