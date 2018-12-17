/* 931. Minimum Falling Path Sum
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12. */

//1. sqaure
/* A falling path starts at any element in the first row, and chooses one element from each row.  */
/*  The next row's choice must be in a column that is different from the previous row's column by at most one. */

/* dp(r, c) = A[r][c] + min(dp(r+1, c-1), dp(r+1, c), dp(r+1, c+1)) */

// from bottom right to upper left have the same result as

// avoid flush original result in the matrix A

class Solution
{
  public:
    int minFallingPathSum(vector<vector<int>> &A)
    {
        if (A.size() == 0)
            return 0;

        int N = A.size();

        // last row dp equal original value in A

        for (int r = N - 2; r >= 0; r--)
        {
            for (int c = 0; c < N; c++)
            {
                // best = min(A[r+1][c-1], A[r+1][c], A[r+1][c+1])
                int best = A[r + 1][c]; // overwrite original A to save memory
                if (c > 0)
                    best = min(best, A[r + 1][c - 1]);
                if (c + 1 < N)
                    best = min(best, A[r + 1][c + 1]);
                A[r][c] += best;
            }
        }
        // min value in first row
        int ans = INT_MAX;
        for (auto &v : A[0])
            ans = min(ans, v);
        return ans;
    }
};