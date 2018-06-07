class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = 0;
        size_t i, j;
        for (i = 0; i < nums.size(); ++i) {
            int len_tmp = 0;
            for (j = i; j < nums.size(); ++j) {
                if (nums[j] - nums[i] <= 1)
                    ++len_tmp;
                else
                    break;
            }
            if (nums[--j] - nums[i] == 1 && len < len_tmp)
                swap(len, len_tmp);
        }
        return len;
    }
};
