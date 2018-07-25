class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, size_t> m1;
        unordered_map<char, size_t> m2;
        for (char &ch : ransomNote)
            ++m1[ch];
        for (char &ch : magazine)
            ++m2[ch];
        for (auto ite = m1.begin(); ite != m1.end(); ++ite) {
            auto tmp = m2.find(ite->first);
            if (tmp == m2.end())
                return false;
            else {
                if (ite->second > tmp->second)
                    return false;
            }
        }
        return true;
    }
};
