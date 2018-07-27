class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s = move(to_string(x));
        size_t mid = s.size(), i = 0, j = s.size()-1;
        while (mid != 0) {
            if (s[i] != s[j])
                return false;
            ++i, --j, --mid;
        }
        return true;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x%10 == 0 && x != 0))
            return false;
        int reverseNumber = 0;
        while (reverseNumber < x) {
            reverseNumber = reverseNumber * 10 + x % 10;
            x /= 10;
        }
        return x == reverseNumber || x == reverseNumber/10;
    }
};
