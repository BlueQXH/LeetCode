class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 2)
            return true;
        size_t cnt = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                if (i-2 < 0 || nums[i-2] < nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
                ++cnt;
            }
            if (cnt > 1)
                return false;
        }
        return true;
    }
};
