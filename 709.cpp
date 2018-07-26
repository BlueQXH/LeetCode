class Solution {
public:
    string toLowerCase(string str) {
        for (auto ite = str.begin(); ite != str.end(); ++ite)
                *ite |= 32;
        return str;
    }
};
