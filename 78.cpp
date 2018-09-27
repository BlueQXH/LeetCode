class Solution1 {
public:
    void dfs(vector<vector<int>> &vec, vector<int> &nums, vector<int> tmp, int index) {
        vec.push_back(tmp);
        for (vector<int>::size_type i = index; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(vec, nums, tmp, i+1);
            tmp.erase(prev(tmp.end()));
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, nums, tmp, 0);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(move(tmp));
        for (int num : nums) {
            auto size = ans.size();
            for (vector<vector<int>>::size_type i = 0; i < size; ++i) {
                vector<int> tmp = ans.at(i);
                tmp.push_back(num);
                ans.push_back(move(tmp));
            }
		}
        return ans;
    }
};
