//根据二维矩阵的元素排列特点，从右上角或左下角开始查找，每次排除一行或一列
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.empty() && !matrix[0].empty()) {
            int col = matrix[0].size()-1, row = 0;
            while (row < matrix.size() && col >= 0) {
                if (matrix[row][col] == target)
                    return true;
                else if (matrix[row][col] > target)
                    --col;
                else
                    ++row;
            }
        }
        return false;
    }
};
