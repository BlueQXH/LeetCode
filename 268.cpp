class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        size_t result = 0;
        for (size_t i = 0; i <= nums.size(); ++i)
            result += i;
        for (int &i : nums)
            result -= i;
        return result;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        size_t result = nums.size();
        for (size_t i = 0; i < nums.size(); ++i) {
			result ^= i
            result ^= nums[i];
        return result;
    }
};


