class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        if (k <= 0 || nums.size() <= 1)
            return false;
        std::unordered_map<int, int> nums_map;
        for (size_t i = 0; i < nums.size(); ++i) {
			if (nums_map.find(nums[i] == nums_map.end()))
				nums_map.insert(std::make_pair(nums[i], i));
			else {
				if (i - nums_map[nums[i]] <= k)
					return true;
				else
					nums_map[nums[i]] = i;
			}
		}
		return false;
    }
};
