class Solution
{
  public:
    int maxProfit(int k, vector<int> &prices)
    {
        int len = prices.size();
        if (len < 2)
            return 0;
        if (k > len / 2)
        { // simple case
            int ans = 0;
            for (int i = 1; i < len; ++i)
            {
                ans += max(prices[i] - prices[i - 1], 0);
            }
            return ans;
        }
        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0); 
        int sell[k];

        int cur;
        for (int i = 0; i < len; ++i)
        {
            cur = prices[i];
            for (int j = k; j > 0; --j)
            {
                sell[j] = max(sell[j], buy[j] + cur);
                buy[j] = max(buy[j], sell[j - 1] - cur);
            }
        }
        return sell[k];
    }
};