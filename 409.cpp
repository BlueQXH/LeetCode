class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, size_t> m;
        for (size_t i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end())
                m.insert(make_pair(s[i], 1));
            else
                ++m[s[i]];
        }
        vector<size_t> vec;
        for (auto ite = m.cbegin(); ite != m.cend(); ++ite)
            vec.push_back(ite->second);
        size_t result = 0;
        bool hasPrime = false;
        sort(vec.begin(), vec.end(), greater<size_t>());
        for (auto ite = vec.begin(); ite != vec.end(); ++ite) {
            if (*ite % 2 != 0) {
                result += --(*ite);
                hasPrime = true;
            }
            else if (*ite % 2 == 0)
                result += *ite;
        }
        if (hasPrime)
            ++result;
        return result;
    }
};
