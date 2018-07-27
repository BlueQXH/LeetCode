class Solution1 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        vector<int> max_vec(nums.size(), 0);
        max_vec[0] = nums[0];
        max_vec[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); ++i)
            max_vec[i] = max(max_vec[i-2]+nums[i], max_vec[i-1]);
        return max_vec.back();
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); ++i)
            nums[i] = max(nums[i-1], nums[i]+nums[i-2]);
        int max_sum = nums[0];
        for (size_t j = 0; j < nums.size(); ++j)
            if (max_sum < nums[j])
                swap(max_sum, nums[j]);
        return max_sum;
    }
};
