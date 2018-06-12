class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        size_t i = 0;
        for (i = 0; i < k; ++i)
            sum += nums[i];
        result = sum;
        for (i = 1; i <= nums.size()-k; ++i) {
            sum = sum - nums[i-1] + nums[i+k-1];
            result = max(result, sum);
        }
        return (double)result/k;
    }
};
