class Solution
{

  private:
    vector<vector<int>> nei;

  public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int m = board.size();
        int n = board[0].size();
        nei = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
        }
        else
        {
            dfs(click[0], click[1], board, visited, m, n);
        }

        return board;
    }

    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited, int m, int n)
    {
        visited[i][j] = true;
        if (board[i][j] == 'E')
        {
            int countMine = 0;
            for (int k = 0; k < 8; k++)
            {
                int newCoord[2] = {i + nei[k][0], j + nei[k][1]};
                if (newCoord[0] >= 0 && newCoord[0] < m && newCoord[1] >= 0 && newCoord[1] < n)
                {
                    if (board[newCoord[0]][newCoord[1]] == 'M')
                    {
                        countMine++;
                    }
                }
            }
            if (countMine == 0)
            {
                for (int k = 0; k < 8; k++)
                {
                    int newCoord[2] = {i + nei[k][0], j + nei[k][1]};
                    if (newCoord[0] >= 0 && newCoord[0] < m && newCoord[1] >= 0 && newCoord[1] < n)
                    {
                        if (visited[newCoord[0]][newCoord[1]] == false && board[newCoord[0]][newCoord[1]] == 'E')
                            dfs(newCoord[0], newCoord[1], board, visited, m, n);
                    }
                }
            }
            board[i][j] = countMine > 0 ? '0' + countMine : 'B';
        }
    }
};