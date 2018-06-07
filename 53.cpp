class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        size_t i = 1, n = nums.size();
        int max_cur = nums[0], max_sum = nums[0];
        for (; i < n; ++i) {
            max_cur = max(nums[i], max_cur + nums[i]);
            max_sum = max(max_sum, max_cur);
        }
        return max_sum;
    }
};

class Solution2 {
public:
    int Sub (vector<int>& nums, int first, int last) {
        if (first == last)
            return nums[first];
        int mid = (first + last) / 2;
        int lmax = Sub(nums, first, mid);
        int rmax = Sub(nums, mid + 1, last);
        int left_sum = nums[mid], right_sum = nums[mid + 1], sum = 0;
        for (size_t i = mid; i >= first; --i) {
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }
        sum = 0;
        for (size_t j = mid + 1; j <= last; ++j) {
            sum += nums[j];
            right_sum = max(right_sum, sum);
        }
        return max(max(lmax, rmax), left_sum + right_sum);
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        return Sub(nums, 0, nums.size() - 1);
    }
};
