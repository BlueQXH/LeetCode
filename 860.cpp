class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (size_t i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5)
                ++five;
            else if (bills[i] == 10) {
                if (five <= 0)
                    return false;
                --five;
                ++ten;
            }
            else if (bills[i] == 20) {
                if (five <= 0)
                    return false;
                else {
                    if (ten > 0) {
                        --ten;
                        --five;
                    }
                    else {
                        if (five < 3)
                            return false;
                        else
                            five -= 3;
                    }
                    ++twenty;
                }
            }
        }
        return true;
    }
};
