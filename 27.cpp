class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        size_t i = 0, j = nums.size() - 1;
        while (i != j) {
            if (nums[j] == val)
                --j;
            else {
                if (nums[i] == val)
                    swap(nums[i++], nums[j]);
                else
                    ++i;
            }
        }
        if (nums[i] == val)
            return i;
        return ++i;
    }
};
