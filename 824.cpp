class Solution {
public:
    string toGoatLatin(string S) {
        string result;
        unordered_set<char> se = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        size_t i = 0, cnt = 1;
        while (i < S.size()) {
            size_t j = i;
            while (j < S.size() && S[j] != ' ')
                ++j;
            string tmp = S.substr(i, j-i);
            cout << tmp << endl;
            if (se.find(tmp.front()) != se.end()) {
                tmp = tmp+"ma";
                for (size_t k = 0; k < cnt; ++k)
                    tmp.push_back('a');
                tmp.push_back(' ');
                result = result+tmp;
            }
            else {
                tmp.push_back(tmp.front());
                tmp.erase(0, 1);
                tmp = tmp+"ma";
                for (size_t k = 0; k < cnt; ++k)
                    tmp.push_back('a');
                tmp.push_back(' ');
                result = result+tmp;
            }
            ++cnt;
            i = j+1;
        }
        result.pop_back();
        return result;
    }
};
