class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        size_t i;
        int index;
        for (i = 0; i < nums.size(); ++i) {
            index = abs(nums[i])-1;
            if (nums[index] > 0)
                nums[index] *= -1;
        }
        for (i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                result.push_back(i+1);
        return result;
    }
};
