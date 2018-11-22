class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
	{
        sort(heaters.begin(), heaters.end());
        int result = 0;
        for (size_t i = 0; i < houses.size(); ++i)
		{
            int left, right;
            if (!binary_search(heaters.begin(), heaters.end(), houses[i]))
			{
                auto index = upper_bound(heaters.begin(), heaters.end(), houses[i])-heaters.begin();
                right = (index < heaters.size()) ? heaters[index] - houses[i] : INT_MAX;
                left = (index-1 >= 0) ? houses[i] - heaters[index-1] : INT_MAX;
                result = max(result, min(left, right));
            }
        }
        return result;
    }
};
