class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (vector<int>::const_iterator i = nums.cbegin(); i != nums.cend(); ++i)
            nums_set.insert(*i);
        if (nums_set.size() == nums.size())
            return false;
        else
            return true;
    }
};
