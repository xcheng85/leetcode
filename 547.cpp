class Solution
{
  public:
    int findCircleNum(vector<vector<int>> &M)
    {
        if (M.size() == 0)
            return 0;

        unordered_set<int> visited_cache;
        int ans = 0;

        queue<int> bfs;
        int source = 0;

        bfs.push(0);

        while (!bfs.empty())
        {
            if (!bfs.empty())
            {
                while (!bfs.empty())
                {
                    int currentSource = bfs.front();
                    bfs.pop();
                    visited_cache.insert(currentSource);
                    for (int c = 0; c < M[currentSource].size(); c++)
                    {
                        if (M[currentSource][c] == 1 && visited_cache.find(c) == visited_cache.end())
                        {
                            bfs.push(c);
                        }
                    }
                }
                ans++;
            }
            while (source < M.size())
            {
                if (visited_cache.find(source) == visited_cache.end())
                {
                    bfs.push(source);
                    break;
                }
                else
                {
                    source++;
                }
            }
        }

        return ans;
    }
};