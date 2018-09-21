class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, i = 0, j = height.size()-1;
        while (i != j) {
            if (height[i] < height[j]) {
                ans = max(ans, (j-i)*height[i]);
                ++i;
            }
            else {
                ans = max(ans, (j-i)*height[j]);
                --j;
            }
        }
        return ans;
    }
};
