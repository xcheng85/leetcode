/* Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9. */

// may or may not existed

// recursive transition
// isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1])

// bottomed up , how to get the subproblem state

#include <vector>

class Solution
{
  public:
    bool isSubsetSumExisted(vector<int> nums, int sum)
    {
        int N = nums.size();

        // The value of subset[i][j] will be true if there is a
        // subset of set[0..i-1] with sum equal to j
        bool subset[N + 1][sum + 1];

        // If sum is 0, then answer is true
        for (int i = 0; i <= N; i++)
            subset[i][0] = true;

        // If sum is not 0 and set is empty, then answer is false
        for (int i = 1; i <= sum; i++)
            subset[0][i] = false;

        // Fill the subset table in bottom up manner
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j < nums[i - 1]) // cut one branch
                    subset[i][j] = subset[i - 1][j];

                if (j >= nums[i - 1])
                    subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }

        return subset[n][sum];
    }
};