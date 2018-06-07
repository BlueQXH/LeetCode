class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int result = 0, min_price = prices.at(0);
        for (int &i : prices) {
            min_price = min(min_price, i);
            result = max(result, i - min_price);
        }
        return result;
    }
};
