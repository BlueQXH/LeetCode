class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        size_t i = 0, n = nums.size();
        while (i < n && nums[i] < target)
            ++i;
        return i;
    }
};
