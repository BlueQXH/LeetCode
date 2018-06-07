class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        size_t n1 = nums1.size(), n2 = nums2.size();
        vector<int> tmp, result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if (nums1.size() > nums2.size())
            set_intersection(nums1.cbegin(), nums1.cend(), nums2.cbegin(), nums2.cend(), back_inserter(tmp));
        else
            set_intersection(nums2.cbegin(), nums2.cend(), nums1.cbegin(), nums1.cend(), back_inserter(tmp));
        unique_copy(tmp.cbegin(), tmp.cend(), back_inserter(result));
        return result;
    }
};

class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums_set1, nums_set2;
        size_t i;
        for (i = 0; i < nums1.size(); ++i)
            nums_set1.insert(nums1[i]);
        for (i = 0; i < nums2.size(); ++i)
            nums_set2.insert(nums2[i]);
        vector<int> result;
        if (nums_set1.size() > nums_set2.size())
            set_intersection(nums_set1.cbegin(), nums_set1.cend(), nums_set2.cbegin(), nums_set2.cend(), back_inserter(result));
        else
            set_intersection(nums_set2.cbegin(), nums_set2.cend(), nums_set1.cbegin(), nums_set1.cend(), back_inserter(result));
        return result;
    }
};
