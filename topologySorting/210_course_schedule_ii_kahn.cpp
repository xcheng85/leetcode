class Solution
{
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites)
        {
            graph[edge.second].push_back(edge.first);
            ++indegree[edge.first];
        }
        queue<int> Q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                Q.push(i);

        vector<int> ans;

        int counter = 0;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            ++counter;
            ans.push_back(u);
            for (auto v : graph[u])
            {
                if (--indegree[v] == 0)
                    Q.push(v);
            }
        }
        return counter == numCourses ? ans : vector<int>{};
    }
};