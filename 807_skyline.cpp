class Solution
{
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int N = grid.size();
        int rowMaxes[N];
        int colMaxes[N];

        memset(rowMaxes, 0, sizeof(rowMaxes));
        memset(colMaxes, 0, sizeof(colMaxes));

        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
            {
                rowMaxes[r] = max(rowMaxes[r], grid[r][c]);
                colMaxes[c] = max(colMaxes[c], grid[r][c]);
            }

        int ans = 0;
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                ans += min(rowMaxes[r], colMaxes[c]) - grid[r][c];

        return ans;
    }
};