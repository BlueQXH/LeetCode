class Solution1 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if (row*col != r*c)
            return nums;
        vector<vector<int>> result;
        vector<int> tmp;
        for (size_t i = 0; i < row; ++i)
            for (size_t j = 0; j < col; ++j)
                tmp.push_back(nums[i][j]);
        size_t k = 0;
        for (size_t i = 0; i < r; ++i) {
            vector<int> t;
            for (size_t j = 0; j < c; ++j) {
                t.push_back(tmp[k]);
                ++k;
            }
            result.push_back(move(t));
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if (row*col != r*c)
            return nums;
        vector<vector<int>> result(r, vector<int>(c));
        for (size_t i = 0; i < r*c; ++i)
                result[i/c][i%c] = nums[i/col][i%col];
        return result;
    }
};
