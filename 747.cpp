class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int index = 0, max = nums[0];
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        int second_max = 0;
        for (int &i : nums)
            if (i < max && i > second_max)
                second_max = i;
        if (second_max<<1 <= max)
            return index;
        return -1;
    }
};
