class Solution {
public:
    int firstBadVersion(int n) {
        long left = 0, right = n, mid;
        while (left <= right) {
            mid = (left+right)/2;
            if (isBadVersion(mid))
                right = mid-1;
            else
                left = mid+1;
        }
        return (isBadVersion(mid)) ? mid : mid+1;
    }
};
