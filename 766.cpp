class Solution1 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (size_t i = 1; i < matrix.size(); ++i)
            for (size_t j = 1; j <matrix[i].size(); ++j)
                if (matrix[i][j] != matrix[i-1][j-1])
                    return false;
        return true;
    }
};

class Solution2 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            size_t j = i, k = 0;
            while (j != matrix.size() && k != matrix[0].size()) {
                if (matrix[i][0] != matrix[j][k])
                    return false;
                ++j;
                ++k;
            }
        }
        for (size_t i = 0; i < matrix[0].size(); ++i) {
            size_t j = 0, k = i;
            while (j != matrix.size() && k != matrix[0].size()) {
                if (matrix[0][i] != matrix[j][k])
                    return false;
                ++j;
                ++k;
            }
        }
        return true;
    }
};
