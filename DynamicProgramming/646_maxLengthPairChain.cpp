/* Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4] */

#include <vector>

struct comparator
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};

class Solution
{
  public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int N = pairs.size();
        if (N == 0)
            return 0;

        sort(pairs.begin(), pairs.end(), comparator());

        vector<int> dp(N, 0); 
        dp[0] = 1; 

        int ans = 1; 

        for(int i = 1; i < N; i++){
            dp[i] = 1; 
            for(int j = 0; j < i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};