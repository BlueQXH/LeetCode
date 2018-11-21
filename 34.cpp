class Solution
{
public:
    int getFirstIndex(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left >> 1);
            if (nums.at(mid) < target)
            {
                left = mid+1;
            }
            else if (nums.at(mid) > target)
            {
                right = mid-1;
            }
            else
            {
                if (mid == 0 || (mid - 1 >= 0 && nums.at(mid-1) != target))
                {
                    return mid;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
    int getLastIndex(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left >> 1);
            if (nums.at(mid) < target)
            {
                left = mid+1;
            }
            else if (nums.at(mid) > target)
            {
                right = mid-1;
            }
            else
            {
                if (mid == nums.size()-1 ||(mid + 1 < nums.size() && nums.at(mid+1) != target))
                {
                    return mid;
                }
                else
                {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
	{
        vector<int> ans(2, -1);
        ans.at(0) = getFirstIndex(nums, target);
        ans.at(1) = getLastIndex(nums, target);
        return ans;
    }
};
