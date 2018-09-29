class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

class Solution2 {
public:
    bool My_Next_Permutation(vector<int>::iterator beg, vector<int>::iterator end) {
        if (beg == end)
            return false;
        vector<int>::iterator i = end;
        if (beg == --i)
            return false;
        while (true) {
            vector<int>::iterator j = i, k;
            if (*--i < *j) {
                k = end;
                while (*i >= *--k) ;
                iter_swap(i, k);
                reverse(j, end);
                return true;
            }
            if (i == beg) {
                reverse(beg, end);
                return false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (My_Next_Permutation(nums.begin(), nums.end()));
        return ans;
    }
};
