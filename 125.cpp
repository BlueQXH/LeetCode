class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1)
            return true;
        string::iterator ite2 = stable_partition(s.begin(), s.end(), [](char &ch){return isalpha(ch) || isdigit(ch);});
        string::iterator ite1 = s.begin();
        if (ite1 == ite2)
            return true;
        size_t i = (ite2-ite1)/2;
        --ite2;
        for (; i != 0; ++ite1, --ite2, --i) {
            if (isalpha(*ite1) && isalpha(*ite2)) {
                if ( tolower(*ite1) != tolower(*ite2))
                    return false;
            }
            else if  (isdigit(*ite1) && isdigit(*ite2)) {
                if (*ite1 != *ite2)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
