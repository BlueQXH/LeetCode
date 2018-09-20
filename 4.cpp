class Solution {
public:
    int findKth(vector<int> &nums1, vector<int> &nums2,int k) {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            --k;
            if (nums1[i] < nums2[j]) {
                if (k == 0)
                    return nums1[i];
                ++i;
            }
            else if (k == 0)
                return nums2[j];
            else
                ++j;
        }
        return i >= nums1.size() ? nums2[j+k-1] : nums1[i+k-1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size()+nums2.size();
        if (len & 1)
            return findKth(nums1, nums2, len+1>>1);
        else
            return (findKth(nums1, nums2, (len>>1))+findKth(nums1, nums2, (len>>1)+1))/2.0;
    }
};
