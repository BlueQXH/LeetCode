class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int i = 0, j;
        while (i < S.size()) {
            j = i;
            while (j < S.size() && S[++j] == S[i]);
            if (j-i >= 3) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j-1);
                result.push_back(move(tmp));
            }
            if (j >= S.size())
                break;
            i = j;
        }
        return result;
    }
};
