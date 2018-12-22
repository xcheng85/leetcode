class Solution
{
  public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
        }
        int target = sum / k;
        if (sum % k > 0 || nums[N - 1] > target)
            return false;

        bool dp[1 << N]; // a combination potential to be a subset
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        int total[1 << N]; // partition sum for each combination
        memset(total, 0, sizeof(total));
        // bottom up
        for (int state = 0; state < (1 << N); state++)
        {
            if (!dp[state])
                continue;
            for (int i = 0; i < N; i++)
            {
                int future = state | (1 << i);
                if (state != future && !dp[future])
                {
                    if (nums[i] <= target - (total[state] % target))
                    {
                        dp[future] = true;
                        total[future] = total[state] + nums[i];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};