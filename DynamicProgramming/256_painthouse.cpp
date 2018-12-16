/* Input: [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
             Minimum cost: 2 + 5 + 3 = 10. */

// dp[3]

// start from 0, 1, 2

// bottom up

#include <vector>

class Solution
{
  public:
    int minCost(vector<vector<int>> &costs)
    {
        int N = costs.size();
        if (N == 0)
            return 0;
        // last house end of r,g,b
        int dp[3] = {costs[0][0], costs[0][1], costs[0][2]};
        int ans = INT_MAX;

        for (int i = 1; i < N; i++)
        {
            int newdp[3] = {0, 0, 0};
            newdp[0] = min(dp[1], dp[2]) + costs[i][0];
            newdp[1] = min(dp[0], dp[2]) + costs[i][1];
            newdp[2] = min(dp[0], dp[1]) + costs[i][2];

            dp[0] = newdp[0];
            dp[1] = newdp[1];
            dp[2] = newdp[2];
        }

        return min(min(dp[0], dp[1]), dp[2]);
    }
};