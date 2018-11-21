class Solution1
{
public:
    int singleNumber(vector<int> &nums)
	{
        int result;
        unordered_multiset<int> nums_set;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
		{
            nums_set.insert(*i);
		}
        for (const auto &j : nums_set)
		{
            if (nums_set.count(j) == 1)
			{
                result = j;
                break;
            }
		}
        return result;
    }
};

class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = nums.front();
        for (int i = 1; i < nums.size(); ++i)
        {
            ans ^= nums.at(i);
        }
        return ans;
    }
};
