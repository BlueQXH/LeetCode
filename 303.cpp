class NumArray {
public:
    NumArray(vector<int> nums) : sums(nums) {
        if (sums.empty())
            return;
        sums[0] = nums[0];
        for (size_t i = 1; i < sums.size(); ++i)
            sums[i] = sums[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return (i == 0) ? sums[j] : sums[j]-sums[i-1];
    }
private:
    vector<int> sums;
};
