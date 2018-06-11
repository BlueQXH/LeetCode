class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0, tmp = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1)
                ++tmp;
            else
                tmp = 0;
            sum = max(sum, tmp);
        }
        return sum;
    }
};
