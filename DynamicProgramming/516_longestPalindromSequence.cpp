/* If last and first characters of X are same, then L(0, n-1) = L(1, n-2) + 2.
Else L(0, n-1) = MAX (L(1, n-1), L(0, n-2)). */

/* // Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2  */

#include <string>

class Solution
{
  public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size(); 

        // subproblem is [i,j] is a PalindromeSubstring
        int i, j, cl; // cl is bottom up from 2 ,3, ... n

        int dp[n][n]; // from i to j

        // Strings of length 1 are palindrome of lentgh 1
        for (i = 0; i < n; i++)
            dp[i][i] = 1;

        // Build the table. Note that the lower diagonal values of table are
        // useless and not filled in the process. The values are filled in a
        // manner similar to Matrix Chain Multiplication DP solution (See
        // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of
        // substring
        for (cl = 2; cl <= n; cl++)
        {
            for (i = 0; i < n - cl + 1; i++)
            {
                j = i + cl - 1;
                if (str[i] == str[j] && cl == 2)
                    dp[i][j] = 2;
                else if (str[i] == str[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        return dp[0][n - 1];
    }
};