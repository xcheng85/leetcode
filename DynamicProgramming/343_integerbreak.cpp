/* 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/

class Solution
{
  public:
    int integerBreak(int n)
    {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = 0;
            for (int k = 1; k <= i / 2; k++)
            {
                // key is the extra k*(i-k)
                dp[i] = max(dp[i], max(k * dp[i - k], k * (i - k)));
            }
        }
        return dp[n];
    }
};