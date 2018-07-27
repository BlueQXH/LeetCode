class Solution1 {
public:
    int climbStairs(int n) {
        vector<int> vec(n+1, 0);
        vec[1] = 1;
        vec[2] = 2;
        for (int i = 3; i <= n; ++i)
            vec[i] = vec[i-1] + vec[i-2];
        return vec[n];
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 0; i < n; ++i) {
            int tmp = a+b;
            a = b;
            b = tmp;
        }
        return a;
    }
};
