class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int beg = -1, end = -2;
        int tmp_max = nums[0], tmp_min = nums[nums.size()-1];
        for (int i = 0; i < nums.size(); ++i) {
            tmp_max = max(tmp_max, nums[i]);
            tmp_min = min(tmp_min, nums[nums.size()-i-1]);
            if (tmp_max > nums[i])
                end = i;
            if (tmp_min < nums[nums.size()-i-1])
                beg = nums.size()-i-1;
        }
        return end-beg+1;
    }
};
