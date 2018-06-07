class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index_m1 = m - 1, index_m2 = m + n - 1, index_n = n - 1;
        while (index_m1 >= 0 && index_n >= 0) {
            if (nums1[index_m1] <= nums2[index_n]) {
                nums1[index_m2] = nums2[index_n];
                --index_m2;
                --index_n;
            }
            else {
                nums1[index_m2] = nums1[index_m1];
                --index_m2;
                --index_m1;
            }
        }
        if (index_n >= 0)
            for (; index_n >= 0; --index_n, --index_m2)
                nums1[index_m2] = nums2[index_n];
    }
};
