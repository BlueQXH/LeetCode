class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while (left <= right) {
            mid = left+((right-left)>>1);
            if (nums[mid] == target || nums[left] == target || nums[right] == target)
                return true;
            if (nums[mid] < nums[left]) {
                if (nums[mid] < target && target < nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
            else if (nums[mid] > nums[left]){
                if (target < nums[mid] && nums[left] < target)
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
                ++left;
        }
        return false;
    }
};
