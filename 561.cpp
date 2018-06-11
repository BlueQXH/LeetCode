class Solution1 {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.size() == 2)
            return min(nums[0], nums[1]);
        int result = 0;
        sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); i += 2)
            result += min(nums[i], nums[i-1]);
        return result;
    }
};

class Solution2 {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.size() == 2)
            return min(nums[0], nums[1]);
        int result = 0;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i += 2)
            result += nums[i];
        return result;
    }
};
