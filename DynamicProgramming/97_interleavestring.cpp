#include <string>

class Solution
{
  public:
    bool isInterleave(string s1, string s2, string s3)
    {
        // Find lengths of the two strings
        int M = s1.size(), N = s2.size();

        // Let us create a 2D table to store solutions of
        // subproblems.  C[i][j] will be true if C[0..i+j-1]
        // is an interleaving of A[0..i-1] and B[0..j-1].
        bool dp[M + 1][N + 1];

        memset(dp, 0, sizeof(dp)); // Initialize all values as false.

        // C can be an interleaving of A and B only of sum
        // of lengths of A & B is equal to length of C.
        if ((M + N) != s3.size())
            return false;

        // Process all characters of A and B
        for (int i = 0; i <= M; ++i)
        {
            for (int j = 0; j <= N; ++j)
            {
                // two empty strings have an empty string
                // as interleaving
                if (i == 0 && j == 0)
                    dp[i][j] = true;

                // A is empty
                else if (i == 0 && s2[j - 1] == s3[j - 1])
                    dp[i][j] = dp[i][j - 1];

                // B is empty
                else if (j == 0 && s1[i - 1] == s3[i - 1])
                    dp[i][j] = dp[i - 1][j];

                // Current character of C matches with current character of A,
                // but doesn't match with current character of B
                else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1])
                    dp[i][j] = dp[i - 1][j];

                // Current character of C matches with current character of B,
                // but doesn't match with current character of A
                else if (s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j - 1];

                // Current character of C matches with that of both A and B
                // key
                else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
        }

        return dp[M][N];
    }
};