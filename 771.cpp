class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, size_t> m;
        for (auto &c : S) {
            if (m.find(c) == m.end())
                m[c] = 1;
            else
                ++m[c];
        }
        int result = 0;
        for (auto &c : J)
            if (m.find(c) != m.end())
                result += m[c];
        return result;
    }
};
