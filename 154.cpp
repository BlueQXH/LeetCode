class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums.front();
        int left = 0, right = nums.size()-1, mid;
        while (left < right) {
            mid = left+((right-left)>>1);
            if (nums[right] < nums[mid])
                left = mid+1;
            else if (nums[right] > nums[mid])
                right = mid;
            else
                --right;
        }
        return nums[left];
    }
};
