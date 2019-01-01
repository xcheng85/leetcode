class Solution
{
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        dfs(graph, 0, {}, ans);
        return ans;
    }

    void dfs(vector<vector<int>> &graph, int idx, vector<int> onePath, vector<vector<int>> &res)
    {
        onePath.push_back(idx);
        if (graph[idx].size() == 0)
        {
            res.push_back(onePath);
        }
        else
        {
            for (int i = 0; i < graph[idx].size(); i++)
            {
                dfs(graph, graph[idx][i], onePath, res);
            }
        }
    }
};