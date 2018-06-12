class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = nums[n-1]*nums[n-2]*nums[n-3];
        result = max(result, nums[0]*nums[n-2]*nums[n-1]);
        result = max(result, nums[0]*nums[1]*nums[n-1]);
        result = max(result, nums[0]*nums[1]*nums[2]);
        return result;
    }
};
