// transition formula: countSub(n) = 2*Count(n-1) - Repetition

#include <vector>

class Solution
{
  public:
    int CountDistinctSubsequences(string s)
    {
        unordered_map<char, int> cacheIndex;  // index in the original array

        int N = s.size();

        // dps.si[i] is going to store count of distinct
        // subsequences of length i.
        int dp[N + 1];//

        // Empty substring has only one subsequence
        dp[0] = 1;

        // Traverse through all lengths from 1 to n.
        for (int i = 1; i <= n; i++)
        {
            // Number of subsequences with substring
            // str[0..i-1]
            dp[i] = 2 * dp[i - 1]; 

            // If current character has appeared
            // before, then remove all subsequences
            // ending with previous occurrence.
            if (cache[s[i - 1]] != 0)
                dp[i] = dp[i] - dp[cacheIndex[s[i - 1]]];

            // Mark occurrence of current character
            cacheIndex[s[i - 1]] = (i - 1);
        }

        return dp[n];
    }
};
