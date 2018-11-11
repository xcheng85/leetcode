// list one topology sorting result
#include <vector>
#include <stack>

using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);

        stack<int> dfs;

        for (auto edge : prerequisites)
        {
            graph[edge.second].push_back(edge.first);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
                this->dfs(graph, visited, i, dfs);
        }

        vector<int> ans;
        if (dfs.size() == numCourses)
        {
            while (!dfs.empty())
            {
                ans.push_back(dfs.top());
                dfs.pop();
            }
        }
        return ans;
    }

  private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int courseId, stack<int> &dfs)
    {
        visited[courseId] = true;

        for (int i = 0; i < graph[courseId].size(); i++)
        {
            int neighboringCourseId = graph[courseId][i];
            if (!visited[neighboringCourseId])
                this->dfs(graph, visited, neighboringCourseId, dfs);
        }

        dfs.push(courseId);
    }
};