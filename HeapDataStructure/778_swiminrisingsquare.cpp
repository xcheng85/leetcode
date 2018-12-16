/* Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected. */

#include <vector>
struct GridNode
{
    int row;
    int col;
    int elevation;
    GridNode() : row(0), col(0), elevation(0) {}
    GridNode(int r, int c, int e) : row(r), col(c), elevation(e) {}
};

class Compare
{
  public:
    bool operator()(GridNode &lhs, GridNode &rhs)
    {
        // minimal elevation on top
        return lhs.elevation > rhs.elevation;
    }
};

class Solution
{
  public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int N = grid.size();

        unordered_set<int> visited;
        priority_queue<GridNode, vector<GridNode>, Compare> pq;

        pq.push(GridNode(0, 0, grid[0][0]));
        int ans = 0;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!pq.empty())
        {
            GridNode tmp = pq.top();
            pq.pop();
            ans = max(ans, tmp.elevation);

            // reach destination
            if (tmp.row == N - 1 && tmp.col == N - 1)
                return ans;

            for (int i = 0; i < 4; ++i)
            {
                int cr = tmp.row + dr[i], cc = tmp.col + dc[i];
                int ck = cr * N + cc;
                if (0 <= cr && cr < N && 0 <= cc && cc < N && visited.find(ck) == visited.end())
                {
                    pq.push(GridNode(cr, cc, grid[cr][cc]));
                    visited.insert(ck);
                }
            }
        }

        return ans;
    }
};