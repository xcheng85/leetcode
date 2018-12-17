/* You have to paint all the posts such that no more than two adjacent fence posts have the same color. */

/* 
total[i] = same[i] + diff[i]

same[i]  = diff[i-1]

diff[i] = total[i-1] * (k-1)

initial case 

diff = k, 
same = 0
total = k

 */

// n posts
// k different colors
class Solution
{
  public:
    int numWays(int n, int k)
    {
        if (n <= 0)
            return 0;

        // dp states;
        int diff = k;
        int same = 0;
        int total = diff;

        for (int i = 1; i < n; i++)
        {
            same = diff;
            diff = total * (k - 1);
            total = same + diff;
        }

        return total;
    }
};