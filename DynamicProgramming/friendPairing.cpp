/* f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1) n-th person remains single, we recur 
   for f(n - 1)
2) n-th person pairs up with any of the 
   remaining n - 1 persons. We get (n - 1) * f(n - 2)

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)
 */

class Solution
{
  public:
    int friendPairing(int n)
    {
        int dp0 = 0;
        int dp1 = 1;

        // Filling dp[] in bottom-up manner using
        // recursive formula explained above.
        for (int i = 2; i <= n; i++)
        {
            int newdp1 = dp1 + (i - 1) * dp0;
            dp0 = dp1;
            dp1 = newdp1;
        }

        return dp1;
    }
};