/* Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.  */

// at each step
/* L(i) can be recursively written as:
L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists. */

#include <vector>

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int ans = 1; 

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = 1;

            // try each j before i
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]); 
        }

        return ans;
    }
};