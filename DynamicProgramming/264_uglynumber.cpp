// other solution: pq (much slower)

/*  (1) 1×2, 2×2, 3×2, 4×2, 5×2, …6 * 2,  (7*2 WRONG), 8 *2, multiply must be ugly-number
     (2) 1×3, 2×3, 3×3, 4×3, 5×3, …
     (3) 1×5, 2×5, 3×5, 4×5, 5×5, …
 
 The ugly-number sequence is 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 
 */

#include <vector>

class Solution
{
  public:
    int nthUglyNumber(int n)
    {
        int ans; 
        int currentIdx = 1; 
        vector<int> ugly_series(n, 1);

        int dp[3] = {0, 0, 0};

        for (int i = 1; i < n; i++)
        {
            int next_multiple_2 = ugly_series[dp[0]] * 2;
            int next_multiple_3 = ugly_series[dp[1]] * 3;
            int next_multiple_5 = ugly_series[dp[2]] * 5;
        

            ugly_series[currentIdx++] = ans = min(min(next_multiple_2, next_multiple_3), next_multiple_5);
            
            if (ans == next_multiple_2)
            {
                dp[0]++;
            }
            if (ans == next_multiple_3)
            {
                dp[1]++;
            }
            if (ans == next_multiple_5)
            {
                dp[2]++;
            }
        }

        return ugly_series[n - 1];
    }
};