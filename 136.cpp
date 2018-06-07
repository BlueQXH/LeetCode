class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result;
        unordered_multiset<int> nums_set;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
            nums_set.insert(*i);
        for (auto &j : nums_set)
            if (nums_set.count(j) == 1) {
                result = j;
                break;
            }
        return result;
    }
};
