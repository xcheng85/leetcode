/* 91. Decode Ways */

#include <string>

class Solution
{
  public:
    int numDecodings(string s)
    {
        int N = s.size();

        int dp[N + 1];

        dp[0] = 1;
        if (s[0] != '0')
            dp[1] = 1;
        else
        {
            dp[1] = 0;
        }

        // length;
        for (int i = 2; i <= N; i++)
        {
            dp[i] = 0;

            // If the last digit is not 0, then last digit must add to
            // the number of words
            if (s[i - 1] > '0')
                dp[i] = dp[i - 1];

            // If second last digit is smaller than 2 and last digit is
            // smaller than 7, then last two digits form a valid character
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
                dp[i] += dp[i - 2];
        }
        return dp[N];
    }
};