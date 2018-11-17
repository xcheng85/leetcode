/* Input : [ 1, 2, 3, 0, 2 ] Output : 3 Explanation : transactions = [ buy, sell, cooldown, buy, sell ]

                                                   // cooldown --> buy
                                                   // buy --- > sell
                                                   // sell ---> cooldown

                                                   cooldown = max(cooldown, sell);
buy = max(cooldown - val, buy);
sell = max(buy + val, sell);

Timestamp - 1 0 1 2 3 4 cooldown 0 0 0 1 2 2 buy - 1 - 1 - 1 - 1 1 1 sell 0 0 1 2 2 3 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;

        int cooldown, buy, sell;

        cooldown = sell = 0;
        buy = -prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            int newcooldown = max(cooldown, sell);
            int newbuy = max(cooldown - prices[i], buy);
            int newsell = max(buy + prices[i], sell);

            cooldown = newcooldown;
            buy = newbuy;
            sell = newsell;
        }

        return sell;
    }
};