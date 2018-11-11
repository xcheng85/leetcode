class Solution
{
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        for (auto edge : prerequisites)
        {
            graph[edge.second].push_back(edge.first);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(graph, visited, i))
                return false;
        }
        return true;
    }

  private:
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int courseId)
    {
        // cycle
        if (visited[courseId])
            return false;
        visited[courseId] = true;

        for (int i = 0; i < graph[courseId].size(); i++)
        {
            if (!dfs(graph, visited, graph[courseId][i]))
                return false;
        }

        visited[courseId] = false;
        return true;
    }
};