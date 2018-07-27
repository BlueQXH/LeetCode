class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t left = 0, right = nums.size()-1, mid = nums.size()/2;
        while (left <= right && mid < nums.size()) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
            mid = (left+right)/2;
        }
        return -1;
    }
};
