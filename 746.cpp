class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cur = (cost[1] <= cost[0]) ? cost[1] : cost[0];
        int pre1 = 0, pre2 = 0;
        for (size_t i = 2; i <= cost.size(); ++i) {
            cur = min(pre1+cost[i-1], pre2+cost[i-2]);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};
