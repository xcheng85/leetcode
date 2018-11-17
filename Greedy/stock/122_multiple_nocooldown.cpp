class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;

        int buy, sell;

        sell = 0;
        buy = -prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            int newbuy = max(sell - prices[i], buy);
            int newsell = max(buy + prices[i], sell);

            buy = newbuy;
            sell = newsell;
        }

        return sell;
    }
};