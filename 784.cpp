class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> s_vec;
        permutation(s_vec, S, 0);
        return s_vec;
    }
private:
    void permutation (vector<string> &vec, string s, size_t index) {
        if (index == s.size())
            vec.push_back(move(s));
        else {
            if (isalpha(s[index])) {
                permutation(vec, s, index+1);
                if (isupper(s[index])) {
                    s[index] = tolower(s[index]);
                    permutation(vec, s, index+1);
                }
                else {
                    s[index] = toupper(s[index]);
                    permutation(vec, s, index+1);
                }
            }
            else
                permutation(vec, s, index+1);
        }
    }
};
