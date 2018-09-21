class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            while(i > 0 && i < nums.size() && nums[i] == nums[i-1])
                ++i;
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                if (nums[k] < 0)
                    break;
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> tmp {nums[i], nums[j], nums[k]};
                    ans.push_back(move(tmp));
                    ++j, --k;
                    while(j < k && nums[j] == nums[j-1])
                        ++j;
                    while(k > j && nums[k] == nums[k+1])
                        --k;
                }
                else if (sum < 0) {
                    ++j;
                    while(j < k && nums[j] == nums[j-1])
                        ++j;
                }
                else {
                    --k;
                    while(k > j && nums[k] == nums[k+1])
                        --k;
                }
            }
        }
        return ans;
    }
};
