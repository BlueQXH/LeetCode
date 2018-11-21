class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ans;
        if (k <= nums.size() && k >= 1)
        {
            deque<int> index;
            for (int i = 0; i < k; ++i)
            {
                while (!index.empty() && nums[i] >= nums[index.back()])
                {
                    index.pop_back();
                }
                index.push_back(i);
            }
            for (int j = k; j < nums.size(); ++j)
            {
                ans.push_back(nums[index.front()]);
                while (!index.empty() && nums[j] >= nums[index.back()])
                {
                    index.pop_back();
                }
                if (!index.empty() && index.front() <= j-k)
                {
                    index.pop_front();
                }
                index.push_back(j);
            }
            ans.push_back(nums[index.front()]);
        }
        return ans;
    }
};
