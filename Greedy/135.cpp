// candy problem 

// key, left and right

// just larger than neighbor by 1

class Solution
{
  public:
    int candy(vector<int> &ratings)
    {
        int sum = 0;

        vector<int> dp(ratings.size(), 1); // at least 1 candy

        // consider left neighbor first

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }

        // consider right neighbor
        sum += dp[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                dp[i] = max(dp[i], dp[i + 1] + 1);
            }
            sum += dp[i];
        }

        return sum;
    }
};
