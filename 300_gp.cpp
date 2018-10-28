Input : [ 10, 9, 2, 5, 3, 7, 101, 18 ] Output : 4 Explanation : The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4. class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {

        int result = 1;

        int n = nums.size();

        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            int maxLength_i = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    maxLength_i = max(dp[i], dp[j] + 1);
                }
            }
            result = max(maxLength_i, result);
            dp[i] = maxLength_i;
        }

        return result;
    }
};

class Solution
{
  public:
    // There's a typical DP solution with O(N^2) Time and O(N) space
    // DP[i] means the result ends at i
    // So for dp[i], dp[i] is max(dp[j]+1), for all j < i and nums[j] < nums[i]
    int lengthOfLIS(vector<int> &nums)
    {
        const int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        vector<int> dp(size, 1);
        int res = 1;
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};