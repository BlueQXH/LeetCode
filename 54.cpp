class Solution {
public:
    void printCircleOfMatrix(vector<vector<int>> &matrix, vector<int> &vec, int start) {
        int endX = matrix[0].size()-start-1, endY = matrix.size()-start-1, i;
        //从左到右
        for (i = start; i <= endX; ++i)
            vec.push_back(matrix[start][i]);
        //从上到下
        if (start < endY)
            for (i = start+1; i <= endY; ++i)
                vec.push_back(matrix[i][endX]);
        //从右到左
        if (start < endX && start < endY)
            for (i = endX-1; i >= start; --i)
                vec.push_back(matrix[endY][i]);
        //从下到上
        if (start < endY-1 && start < endX)
            for (i = endY-1; i >= start+1; --i)
                vec.push_back(matrix[i][start]);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty())
            return result;
        int rows = matrix.size(), columns = matrix[0].size();
        result.reserve(rows*columns);
        int start = 0;
        while (rows > 2*start && columns > 2*start) {
            printCircleOfMatrix(matrix, result, start);
            ++start;
        }
        return result;
    }
};

/*	为了避免多次重新调整vector大小带来的额外开销，可以
使用成员函数resize预先分配空间，使用成员函数reserve也
可以，但无法通过赋值而需要使用push_back	*/

