class Solution1 {
public:
    bool isPerfectSquare(int num) {
        long int left = 0, right = num, result = 1, mid;
        while (left <= right) {
            mid = (left+right)/2;
            result = mid*mid;
            if (result < num)
                left = mid+1;
            else if (result > num)
                right = mid-1;
            else
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
