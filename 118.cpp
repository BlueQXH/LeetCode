class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (size_t i = 0; i < numRows; ++i) {
            vector<int> tmp;
            if (i == 0)
                tmp.push_back(1);
            else
                for (size_t j = 0; j <= i; ++j) {
                    if (j == 0 || j == i)
                        tmp.push_back(1);
                    else
                        tmp.push_back(result[i-1][j-1] + result[i-1][j]);
                }
            result.push_back(tmp);
        }
        return result;
    }
};
