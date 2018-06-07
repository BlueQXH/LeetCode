class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        vector<int>::iterator pre = nums.begin(), next = nums.begin();
        while (++next != nums.end()) {
            if (*pre != *next)
                *++pre = *next;
        }
        return ++pre - nums.begin();
    }
};
