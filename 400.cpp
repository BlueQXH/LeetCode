class Solution
{
public:
    long getIndex(long n, long digits)
    {
        int number = n/digits + (digits == 1 ? 0 : static_cast<int>(pow(10, digits-1)));
        for (int i = 1; i < digits - n%digits; ++i)
        {
            number /= 10;
        }
        return number%10;
    }
    
    long findNthDigit(long n)
    {
        if (n < 0)
        {
            return -1;
        }
        int digits = 1;
        for(;;)
        {
            long cnt = digits * (digits == 1 ? 10 : 9 * static_cast<long>(pow(10, digits-1)));
            if (n < cnt)
            {
                return getIndex(n, digits);
            }
            n -= cnt;
            ++digits;
        }
        return -1;
    }
};
