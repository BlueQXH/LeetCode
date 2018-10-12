class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while (left <= right) {
            mid = left+((right-left)>>1);
            if (nums[mid] == target)
                return mid;
            else if (nums[left] == target)
                return left;
            else if (nums[right] == target)
                return right;
            if (nums[mid] < nums[left]) {
                if (target < nums[right] && target > nums[mid])
                    left = mid+1;
                else
                    right = mid-1;
            }
            else {
                if (nums[mid] > target && nums[left] < target)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return -1;
    }
};
