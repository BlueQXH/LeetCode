class Solution {
public:
    int rotatedDigits(int N) {
        unordered_set<int> se1 = {0, 1, 8};
        unordered_set<int> se2 = {2, 5, 6, 9};
        int result = 0;
        for (int i = 1; i <= N; ++i) {
            int tmp = i;
            bool isGood = false;
            while (tmp > 0) {
                if (se1.find(tmp%10) == se1.end() && se2.find(tmp%10) == se2.end()) {
                    isGood = false;
                    break;
                }
                else if (se2.find(tmp%10) != se2.end())
                    isGood = true;
                tmp /= 10;
            }
            if (isGood)
                ++result;
        }
        return result;
    }
};
