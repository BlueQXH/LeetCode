class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<size_t>> m;
        for (size_t i = 0; i < nums.size(); ++i)
            m[nums[i]].push_back(i);
        size_t max_d = 0;
        for (unordered_map<int, vector<size_t>>::const_iterator ite = m.cbegin(); ite != m.cend(); ++ite)
            max_d = max(max_d, ite->second.size());
        int result = INT_MAX;
        for (unordered_map<int, vector<size_t>>::const_iterator ite = m.cbegin(); ite != m.cend(); ++ite)
            result = (ite->second.size() == max_d && result > ite->second.back() - ite->second.front() + 1) ? ite->second.back() - ite->second.front() + 1 : result;
        return result;
    }
};
