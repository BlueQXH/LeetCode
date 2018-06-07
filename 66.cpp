class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        do {
            if (digits[i] == 9) {
                digits[i--] = 0;
                continue;
            }
            else {
                digits[i] += 1;
                break;
            }
        } while (i >= 0);
        if (i == -1 && digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
