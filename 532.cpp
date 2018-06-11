class Solution1 {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 0)
            return 0;
        int result = 0;
        unordered_map<int, size_t> m;
        for (int &i : nums)
            ++m[i];
        if (k == 0) {
            for (auto &p : m)
                if (p.second > 1)
                    ++result;
            return result;
        }
        for (auto &p : m)
            if (m.find(p.first+k) != m.end())
                ++result;
        return result;
    }
};

class Solution2 {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 0)
            return 0;
        int result = 0;
        sort(nums.begin(), nums.end());
        size_t left = 0, right = 1;
        while (right < nums.size()) {
            if (nums[right] - nums[left] == k) {
                ++result;
                ++left;
                int tmp = nums[right];
                while (nums[right] == tmp)
                    ++right;
            }
            else if (nums[right] - nums[left] < k)
                ++right;
            else
                ++left;
            if (left == right)
                ++right;
        }
        return result;
    }
};
