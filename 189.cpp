class Solution1 {
public:
    void RightShift (vector<int>& nums) {
        int tmp = nums[nums.size()-1];
        for (size_t i = nums.size()-1; i > 0; --i)
            nums[i] = nums[i-1];
        nums[0] = tmp;
    }
    void rotate(vector<int>& nums, int k) {
        for (int i = k; i > 0; --i)
            RightShift(nums);
    }
};

class Solution2 {
public:
    void Reverse (vector<int>& nums, size_t left, size_t right) {
        for (; left < right; ++left, --right)
            swap(nums[left], nums[right]);
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0)
            return;
        Reverse(nums, 0, nums.size()-k-1);
        Reverse(nums, nums.size()-k, nums.size()-1);
        Reverse(nums, 0, nums.size()-1);
    }
};
