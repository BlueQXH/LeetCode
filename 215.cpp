class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k || k <= 0 || nums.empty())
            return -1;
        int start = 0, end = nums.size();
        while (start < end) {
            int i = start, j = end-1, key = nums[start];
            while (i <= j) {
                while (i <= j && nums[i] >= key)
                    ++i;
                while (i <= j && nums[j] < key)
                    --j;
                if (i < j)
                    swap(nums[i++], nums[j--]);
            }
            swap(nums[start], nums[j]);
            if (j < k-1)
                start = j+1;
            else if (j > k-1)
                end = j;
            else
                return nums[j];
        }
        return -1;
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int result;
        for (size_t i = 0; i < k; ++i) {
            result = nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return result;
    }
};
