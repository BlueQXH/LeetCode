class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 1;
        while (A[i] > A[i-1] && i < A.size())
            ++i;
        return i-1;
    }
};
