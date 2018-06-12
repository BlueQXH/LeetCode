class Solution {
public:
    int getAve (vector<vector<int>>& m, int x, int y) {
        int sum = m[x][y], cnt = 1;
        if (x-1 >= 0 && y-1 >= 0) {
            sum += m[x-1][y-1];
            ++cnt;
        }
        if (y-1 >= 0) {
            sum += m[x][y-1];
            ++cnt;
        }
        if (x+1 < m.size() && y-1 >= 0) {
            sum += m[x+1][y-1];
            ++cnt;
        }
        if (x+1 < m.size()) {
            sum += m[x+1][y];
            ++cnt;
        }
        if (x+1 < m.size() && y+1 < m[0].size()) {
            sum += m[x+1][y+1];
            ++cnt;
        }
        if (y+1 < m[0].size()) {
            sum += m[x][y+1];
            ++cnt;
        }
        if (x-1 >= 0 && y+1 < m[0].size()) {
            sum += m[x-1][y+1];
            ++cnt;
        }
        if (x-1 >= 0) {
            sum += m[x-1][y];
            ++cnt;
        }
        return floor((double)sum/cnt);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> result = M;
        for (size_t i = 0; i < M.size(); ++i)
            for (size_t j = 0; j < M[0].size(); ++j)
                result[i][j] = getAve(M, i, j);
        return result;
    }
};
