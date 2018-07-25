class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1)
            return true;
        bool isOK;
        if (islower(word[0])) {
            for (size_t i = 1; i < word.size(); ++i)
                if (isupper(word[i]))
                    return false;
        }
        else {
            if (islower(word[1])) {
                for (size_t i = 1; i < word.size(); ++i)
                    if (isupper(word[i]))
                        return false;
            }
            else {
                for (size_t j = 1; j < word.size(); ++j)
                    if (islower(word[j]))
                        return false;
            }
        }
        return true;
    }
};
