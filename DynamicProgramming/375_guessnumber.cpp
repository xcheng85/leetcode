/* 375. Guess Number Higher or Lower II */
class Solution
{
  public:
    int getMoneyAmount(int n)
    {
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i <= n - len + 1; i++)
            {
                int minRes = INT_MAX;
                for (int k = i; k < i + len - 1; k++)
                {
                    minRes = min(k + max(dp[i][k - 1], dp[k + 1][i + len - 1]), minRes);
                }
                dp[i][i + len - 1] = minRes;
            }
        }

        return dp[1][n];
    }
};

/* 
 int[][] dp = new int[n + 1][n + 1];
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minres = Integer.MAX_VALUE;
                for (int piv = start; piv < start + len - 1; piv++) {
                    int res = piv + Math.max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = Math.min(res, minres);
                }
                dp[start][start + len - 1] = minres;
            }
        }
        return dp[1][n];
    } */