class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() <= 2)
            return -1;
        size_t i = 0, j = nums.size()-1;
        ptrdiff_t sum = 0, lsum = 0;
        for (int &i : nums)
            sum += i;
        for (int i = 0; i < nums.size(); ++i) {
            lsum += nums[i];
            if (lsum == sum - lsum + nums[i])
                return i;
        }
        return -1;
    }
};
