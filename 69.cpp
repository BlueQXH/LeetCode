class Solution1 {
public:
    int mySqrt(int x) {
        long int left = 0, right = x, result = 1, mid;
        while (left <= right) {
            mid = (left+right)/2;
            result = mid*mid;
            if (result < x)
                left = mid+1;
            else if (result > x)
                right = mid-1;
            else
                return mid;
        }
        return (left+right)/2;
    }
};

class Solution2 {
public:
    int mySqrt(int x) {
        double pre = 0;
        double cur = x; 
        while(abs(cur - pre) > 0.000001){
            pre = cur;
            cur = (pre/2 + x/(2*pre));
        }
        return int(cur);
    }
};
