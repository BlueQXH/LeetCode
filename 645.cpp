class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result(2);
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] >= 0)
                nums[index] = -nums[index];
            else
                result[0] = index + 1;
        }
        for (int j = 0; j < nums.size(); ++j)
            if (nums[j] > 0)
                result[1] = j + 1;
        return result;
    }
};
