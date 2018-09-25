class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int dis = abs(ans-target);
        for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
            int tmp = 0, sum = 0;
            vector<int>::size_type j = i+1, k = nums.size()-1;
            while (j < k) {
                sum = nums[i]+nums[j]+nums[k];
                tmp = abs(sum-target);
                if (dis > tmp) {
                    dis = tmp;
                    ans = sum;
                }
                if (sum == target)
                    return sum;
                else if (sum < target)
                    ++j;
                else
                    --k;
            }
        }
        return ans;
    }
};
