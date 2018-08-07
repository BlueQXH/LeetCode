class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //方向
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int coor[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, di = 0;
        //障碍坐标，存放在set中以提供高效查找
        unordered_set<pair<int, int>> obstacleSet;
        for (size_t i = 0; i < obstacles.size(); ++i)
            obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        int result = 0;
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        result = max(result, x*x + y*y);
                        break;
                    }
                }
            }
        }
        return result;
    }
};
