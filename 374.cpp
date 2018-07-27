class Solution1 {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid;
        while (left <= right) {
            mid = left+(right-left)/2;
            if (guess(mid) == -1)
                right = mid-1;
            else if (guess(mid) == 1)
                left = mid+1;
            else if (guess(mid) == 0)
                return mid;
        }
        return -1;
    }
};

class Solution2 {
public:
    int guessNumber(int n) {
        long left = 1, right = n, mid;
        while (left <= right) {
            mid = (left+right)/2;
            if (guess(mid) == -1)
                right = mid-1;
            else if (guess(mid) == 1)
                left = mid+1;
            else if (guess(mid) == 0)
                return mid;
        }
        return -1;
    }
};
