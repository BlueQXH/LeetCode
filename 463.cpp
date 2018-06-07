class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int grids = 0, side = 0;
        for (size_t i = 0; i < grid.size(); ++i)
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0)
                    continue;
                ++grids;
                if (i != 0 && grid[i-1][j] == 1) ++side;
                if (j != 0 && grid[i][j-1] == 1) ++side;
            }
        return grids*4-side*2;
    }
};
