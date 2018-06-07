class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.resize(rowIndex + 1);
        result[0] = result[rowIndex] = 1;
        for (size_t i = 1; i < (result.size() + 1) / 2; ++i)
            result[i] = result[rowIndex - i] = result[i - 1] * (rowIndex - i + 1) / i;
        return result;
    }
};
