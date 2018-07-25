class Solution1 {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        else if (haystack.size() < needle.size())
            return -1;
        else if (haystack.size() == needle.size()) {
            if (haystack == needle)
                return 0;
            return -1;
        }
        char ch = needle.front();
        for (size_t i = 0; i <= haystack.size()-needle.size(); ++i)
            if (haystack[i] == ch)
                if (haystack.substr(i, needle.size()) == needle)
                    return i;
        return -1;
    }
};
