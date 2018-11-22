class Solution1
{
public:
    void moveZeroes(vector<int> &nums)
	{
        if (nums.size() <= 1)
		{
            return ;
		}
        size_t i = 0, j = 0, n = nums.size();
        for (; j < n; ++j)
		{
            if (nums[j] != 0)
			{
                nums[i] = nums[j];
				++i;
			}
		}
        while (i < n)
		{
            nums[i] = 0;
			++i;
		}
    }
};

class Solution2
{
public:
    void moveZeroes(vector<int> &nums)
	{
        if (nums.size() <= 1)
		{
            return ;
		}
        size_t i = 0, j = 0, n = nums.size();
        for (; j < n; ++j)
		{
            if (nums[j] != 0)
			{
                swap(nums[i], nums[j]);
				++i;
			}
		}
    }
};
