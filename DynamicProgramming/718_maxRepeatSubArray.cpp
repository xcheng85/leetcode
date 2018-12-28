/* Input: */
/* A: [1,2,3,2,1] */
/* B: [3,2,1,4,7] */
/* Output: 3 */
/* Explanation:  */
/* The repeated subarray with maximum length is [3, 2, 1]. */

// continuous sub array

class Solution
{
  public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        int N = A.size();
        int M = B.size();

        int dp[N + 1][M + 1];
        int ans = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }

        return ans;
    }
};