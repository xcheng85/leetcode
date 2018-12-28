class Solution
{
  public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();

        // Create a table to store solutions of subproblems
        int dp[n][n]; // start element to end element index
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }

        for (int len = 1; len < n; len++)
        {
            for (int i = 0; i < n - len; i++)
            {
                //i: start index
                //j: end index
                int j = i + len;
                //cout << i+1 << " " << j << endl;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
                //cout << i << " " << j << endl;
            }
        }

        return dp[0][n - 1] >= 0;
    }
};