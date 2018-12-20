class Solution
{
  public:
    int maxCoins(vector<int> &iNums)
    {
        int n = iNums.size();
        // key
        iNums.insert(iNums.begin(), 1);
        iNums.insert(iNums.end(), 1);

        vector<vector<int>> dp(iNums.size(), vector<int>(iNums.size(), 0));

        // use length to bottom up
        for(int l = 1; l <= n; l++){
            for(int s = 1; s <= n - l + 1; s++){
                int e = s + l - 1; 
            
                // boundary case
                int maxvalue = 0;
                for(int b = s; b <= e; b++){
                    maxvalue = max(maxvalue, iNums[s - 1] *iNums[b]*iNums[e + 1] + dp[s][b-1]+dp[b+1][e]);
                }
                dp[s][e] = maxvalue;
            }
        }

        return dp[1][n];
    }
};