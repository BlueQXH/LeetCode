class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        size_t i = 0, j = 1;
        size_t result = 0;
        while (j < nums.size()) {
            if (nums[j] > nums[j-1])
                ++j;
            else {
                result = max(result, j-i);
                i = j;
                ++j;
            }
        }
        result = max(result, j-i);
        return result;
    }
};
