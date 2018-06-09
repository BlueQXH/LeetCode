class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        unordered_map<int, size_t> m;
        for (int &i : nums) {
            if (m.find(i) == m.end())
                m[i] = 1;
            else
                ++m[i];
        }
        for (unordered_map<int, size_t>::value_type &p : m)
            if (p.second > nums.size()/2)
                return p.first;
        return 0;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution3 {
public:
    int DC_find (vector<int> & nums, int left, int right) {
        if (left == right)
            return nums[left];
        int mid = (left + right)/2;
        int lnum = DC_find(nums, left, mid);
        int rnum = DC_find(nums, mid+1, right);
        if (lnum == rnum)
            return lnum;
        else {
            int l_cnt = 0, r_cnt = 0;
            for (int i = 0; i <= right; ++i) {
                if (nums[i] == lnum)
                    ++l_cnt;
                else if (nums[i] == rnum)
                    ++r_cnt;
            }
            if (l_cnt <= r_cnt)
                return rnum;
            else
                return lnum;
        }
    }
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        return DC_find(nums, 0, nums.size()-1);
    }
};

class Solution4 {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int cnt = 0, result = nums[0];
        for (size_t i = 0; i < nums.size(); ++i) {
            if (cnt == 0 || result == nums[i]) {
                ++cnt;
                result = nums[i];
            }
            else
                --cnt;
        }
        return result;
    }
};
