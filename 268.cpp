class Solution1
{
public:
    int missingNumber(vector<int> &nums)
	{
        size_t result = 0;
        for (size_t i = 0; i <= nums.size(); ++i)
            result += i;
        for (int &i : nums)
            result -= i;
        return result;
    }
};

class Solution2
{
public:
    int missingNumber(vector<int> &nums)
	{
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i)
		{
			//利用异或运算的性质：x^y^y = x
			result ^= i
            result ^= nums[i];
		}
        return result;
    }
};


