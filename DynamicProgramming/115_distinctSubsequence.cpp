/* // An empty string is subsequence of all.
   1) If length of T is 0, return 1.

   // Else no string can be a sequence of empty S.
   2) Else if S is empty, return 0.
    
   3) Else if last characters of S and T don't match,
      remove last character of S and recur for remaining
        return subsequenceCount(S, T, n-1, m)

   4) Else (Last characters match), the result is sum
      of two counts.
        
        // Remove last character of S and recur.
        a) subsequenceCount(S, T, n-1, m) + 

        // Remove last characters of S and T, and recur.
        b) subsequenceCount(S, T, n-1, m-1)   */

#include <string>

class Solution
{
  public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] != t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};