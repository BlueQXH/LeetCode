class Solution
{
public:
    int maxArea(vector<int> &height)
	{
        int ans = 0, i = 0, j = height.size()-1;
        while (i != j)
		{
			int area = 0;
            if (height[i] < height[j])
			{
				area = (j-i)*height[i];
				if (ans < area)
				{
					ans = area;
					++i;
				}
            }
            else
			{
				area = (j-i)*height[j];
				if (ans < area)
				{
					ans = area;
					--j;
				}
            }
        }
        return ans;
    }
};
