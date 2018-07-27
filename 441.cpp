class Solution1 {
public:
    int arrangeCoins(int n) {
        int line = 0;
        while (n >= 0) {
            ++line;
            n -= line;
        }
        return (n == 0) ? line : line-1;
    }
};

class Solution2 {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n, mid;
        while (left <= right){
            mid = (left+right) >> 1;
            if ((0.5*mid*mid+0.5*mid) <= n){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left-1;
    }
};
