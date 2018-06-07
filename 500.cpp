class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string character1("qwertyuiopQWERTYUIOP");
        string character2("asdfghjklASDFGHJKL");
        string character3("zxcvbnmZXCVBNM");
        unordered_set<char> ch_set1;
        unordered_set<char> ch_set2;
        unordered_set<char> ch_set3;
        vector<string> result;
        size_t i, j;
        for (i = 0; i < character1.size(); ++i)
            ch_set1.insert(character1[i]);
        for (i = 0; i < character2.size(); ++i)
            ch_set2.insert(character2[i]);
        for (i = 0; i < character3.size(); ++i)
            ch_set3.insert(character3[i]);
        for (i = 0; i < words.size(); ++i) {
            bool isOK = true;
            if (ch_set1.find(words[i][0]) != ch_set1.end()) {
                for (j = 1; j < words[i].size(); ++j)
                    if (ch_set1.find(words[i][j]) == ch_set1.end()) {
                        isOK = false;
                        break;
                    }
            }
            else if (ch_set2.find(words[i][0]) != ch_set2.end()) {
                for (j = 1; j < words[i].size(); ++j)
                    if (ch_set2.find(words[i][j]) == ch_set2.end()) {
                        isOK = false;
                        break;
                    }
            }
            else if (ch_set3.find(words[i][0]) != ch_set3.end()) {
                for (j = 1; j < words[i].size(); ++j)
                    if (ch_set3.find(words[i][j]) == ch_set3.end()) {
                        isOK = false;
                        break;
                    }
            }
            if (isOK)
                result.push_back(words[i]);
        }
        return result;
    }
};
