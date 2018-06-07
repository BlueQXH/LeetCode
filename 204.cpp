class Solution1 {
public:
    size_t countPrimes(size_t n) {
        bool *p = new bool[n+1];
        size_t i, j;
        for (i = 0; i <= n; ++i)
            p[i] = true;
        p[0] = p[1] = false;
        for (i = 2; i < n; ++i)
                if (p[i])
                    for (j = 2; i*j < n; ++j)
                        p[i*j] = false;
        size_t cnt = 0;
        for (i = 2; i < n; ++i)
            if (p[i])
                cnt++;
        return cnt;
    }
};

class Solution2 {
public:
    size_t countPrimes(size_t n) {
        bool *p = new bool[n+1];
        size_t i, j;
        p[0] = p[1] = false;
        for (i = 2; i <= n; ++i)
            p[i] = true;
        for (i = 2; i < n; ++i)
                if (p[i])
                    for (j = i*i; j < n; j += i)
                        p[j] = false;
        size_t cnt = 0;
        for (i = 2; i < n; ++i)
            if (p[i])
                cnt++;
        return cnt;
    }
};
