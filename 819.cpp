class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s_ban;
        unordered_map<string, size_t> m_par;
        for (string &s : banned)
            s_ban.insert(s);
        stringstream ss(paragraph);
        string word;
        while (ss >> word) {
            if (!isalpha(word.back()))
                word.pop_back();
            for (size_t i = 0; i < word.size(); ++i)
                word[i] = tolower(word[i]);
            ++m_par[word];
        }
        string result;
        size_t max = 0;
        for (auto ite = m_par.begin(); ite != m_par.end(); ++ite) {
            if (s_ban.find(ite->first) == s_ban.end() && ite->second > max) {
                result = ite->first;
                max = ite->second;
            }
        }
        return result;
    }
};
