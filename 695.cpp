class Solution {
public:
    int dfs (vector<vector<int>>& grid, int x, int y, int &area) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return area;
        ++area;
        grid[x][y] = 0;
        dfs(grid, x, y-1, area);
        dfs(grid, x, y+1, area);
        dfs(grid, x-1, y, area);
        dfs(grid, x+1, y, area);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (size_t i = 0; i < grid.size(); ++i)
            for (size_t j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1) {
                    int area = 0;
                    result = max(result, dfs(grid, i, j, area));
                }
        return result;
    }
};
