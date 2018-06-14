class Solution1 {
public:
    int judge(vector<vector<int>>& grid, int x, int y) {
        vector<int> tmp(10);
        for (int i = x; i < x+3; ++i)
            for (int j = y; j < y+3; ++j) {
                if (grid[i][j] > 9 || grid[i][j] < 1)
                    return 0;
                ++tmp[grid[i][j]];
                if (tmp[grid[i][j]] > 1)
                    return 0;
            }
        int sum = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        if (sum != grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2])
            return 0;
        for (int i = x; i < x+3; ++i)
            if (sum != grid[i][y] + grid[i][y+1] + grid[i][y+2])
                return 0;
        for (int j = y; j < y+3; ++j)
            if (sum != grid[x][j] + grid[x+1][j] + grid[x+2][j])
                return 0;
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int result = 0;
        for (int i = 0; i+2 < grid.size(); ++i)
            for (int j = 0; j+2 < grid[i].size(); ++j)
                result += judge(grid, i, j);
        return result;
    }
};

class Solution2 {
public:
    int judge(vector<vector<int>>& grid, int x, int y) {
        if (grid[x-1][y-1] == 0 || grid[x+1][y+1] == 0 || grid[x][y-1] == 0 || grid[x][y+1] == 0 || grid[x+1][y-1] == 0 || grid[x-1][y+1] == 0 || grid[x+1][y] == 0 || grid[x-1][y] == 0)
            return 0;
        return (grid[x-1][y-1]+grid[x+1][y+1] == 10 && grid[x][y-1]+grid[x][y+1] == 10 && grid[x+1][y-1]+grid[x-1][y+1] == 10 && grid[x+1][y]+grid[x-1][y] == 10) ? 1 : 0;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3)
            return 0;
        int result = 0;
        for (int i = 1; i+1 < grid.size(); ++i)
            for (int j = 1; j+1 < grid[i].size(); ++j)
                result += (grid[i][j] == 5) ? judge(grid, i, j) : 0;
        return result;
    }
};
