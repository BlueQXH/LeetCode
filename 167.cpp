class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if (numbers.size() < 1)
            return result;
        int left = 0, right = numbers.size() - 1;
        while (left < right) { //若不存在答案此循环无法结束
            if (numbers[left] + numbers[right] == target) {
                result.push_back(++left);
                result.push_back(++right);
                return result;
            }
            else if (numbers[left] + numbers[right] > target)
                --right;
            else
                ++left;
        }
    }
};
