// two transactions

// four states
// buy the 1st stock
// sell the 1st stock
// buy the 2nd stock
// sell the 2nd stock

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int buy1, buy2, sell1, sell2;

        buy1 = buy2 = INT_MIN; // in possible
        sell1 = sell2 = 0;     // initial money is 0

        for (int i = 0; i < prices.size(); i++)
        {
            sell2 = max(sell2, buy2 + prices[i]);

            buy2 = max(buy2, sell1 - prices[i]);

            sell1 = max(sell1, buy1 + prices[i]);

            buy1 = max(buy1, -prices[i]);
        }

        return sell2;
    }
};