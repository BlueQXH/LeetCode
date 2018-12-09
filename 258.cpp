class Solution1
{
public:
    int addDigits(int num)
    {
        return 1 + (num - 1) % 9;
    }
};

//this solution is faster
class Solution2
{
public:
    int addDigits(int num)
    {
        return num == 0 ? 0 : num%9 == 0 ? 9 : num%9;
    }
};
