class Solution
{
public:
    int minimal(int a, int b, int c)
    {
        return min(min(a, b), c);
    }
    int nthUglyNumber(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        vector<int> vec(n);
        int index_2 = 0, index_3 = 0, index_5 = 0;
        int val_2 = 2, val_3 = 3, val_5 = 5;
        vec[0] = 1;
        for (int i = 1; i < vec.size(); ++i)
        {
            vec[i] = minimal(val_2, val_3, val_5);
            if (vec[i] == val_2)
            {
                val_2 = vec[++index_2]*2;
            }
            if (vec[i] == val_3)
            {
                val_3 = vec[++index_3]*3;
            }
            if (vec[i] == val_5)
            {
                val_5 = vec[++index_5]*5;
            }
        }
        return vec.back();
    }
};
