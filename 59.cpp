class Solution {
public:
    void print(vector<vector<int>> &matrix,int start, int &n) {
        int endX = matrix[0].size()-start-1, endY = matrix.size()-start-1, i;
        //从左到右
        for (i = start; i <= endX; ++i)
            matrix[start][i] = ++n;
        //从上到下
        if (start < endY)
            for (i = start+1; i <= endY; ++i)
                matrix[i][endX] = ++n;
        //从右到左
        if (start < endY && start < endX)
            for (i = endX-1; i >= start; --i)
                matrix[endY][i] = ++n;
        //从下到上
        if (start < endX && start < endY-1)
            for (i = endY-1; i >= start+1; --i)
                matrix[i][start] = ++n;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        if (n <= 0)
            return matrix;
        matrix.resize(n);
        for (size_t i = 0; i < matrix.size(); ++i)
            matrix[i].resize(n);
        int start = 0, num = 0;
        while (matrix.size() > 2*start && matrix[0].size() > 2*start) {
            print(matrix,start, num);
            ++start;
        }
        return matrix;
    }
};
