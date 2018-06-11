class Solution1 {
public:
    int thirdMax(vector<int>& nums) {
        int max = nums[0], min = nums[0];
        size_t i;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] > max)
                max = nums[i];
            if (nums[i] < min)
                min = nums[i];
        }
        if (min == max)
            return max;
        int second_max = min;
        for (i = 0; i < nums.size(); ++i)
            if (nums[i] < max && nums[i] > second_max)
                second_max = nums[i];
        if (second_max == min)
            return max;
        int result = min;
        for (i = 0; i < nums.size(); ++i)
            if (nums[i] < second_max && nums[i] > result)
                result = nums[i];
        return result;
    }
};


