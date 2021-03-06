class Solution
{
public:
    int guessNumber(int n)
	{
        int left = 1, right = n, mid;
        while (left <= right) {
            mid = left + (right-left >> 1);
            if (guess(mid) == -1)
			{
                right = mid-1;
			}
            else if (guess(mid) == 1)
			{
                left = mid+1;
			}
            else
			{
                return mid;
			}
        }
        return -1;
    }
};
