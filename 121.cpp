class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() <= 1)
		{
            return 0;
		}
        int result = 0, min_price = prices.at(0);
        for (int &price : prices)
        {
            if (price < min_price)
            {
                min_price = price;
            }
            else
            {
                if (result < price - min_price)
                {
                    result = price - min_price;
                }
            }
        }
        return result;
    }
};
