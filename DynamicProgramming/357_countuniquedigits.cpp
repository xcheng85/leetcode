class Solution
{
  public:
    int count(int i)
    {
        long long temp = 1;
        temp = temp * 9;
        i--;
        while (i > 0)
        {
            temp = temp * (10 - i);
            i--;
        }
        return temp;
    }
    int countNumbersWithUniqueDigits(int n)
    {

        long long ans;
        vector<long long> dp(11, 0);
        dp[0] = 1;
        dp[1] = 10;
        /*
        n=2  (9*8 + dp[1] = 91)
        n=3   (9*9*8 + dp[2] = 739)
        
        */
        dp[2] = 91;
        for (int i = 3; i <= 10; i++)
        {
            dp[i] = dp[i - 1] + count(i);
        }

        if (n <= 10)
            return dp[n];
        return dp[10];
    }
};