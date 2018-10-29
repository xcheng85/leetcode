
//[[1,0]
//To take course 1 you should have finished course 0. So it is possible.
// bfs (Topological Sort)
class Solution
{
    
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);


        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites)
        {
            graph[edge.second].push_back(edge.first);


            ++indegree[edge.first];
        }

        // sources 

        queue<int> Q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                Q.push(i);


        int counter = 0;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            ++counter;
            for (auto v : graph[u])
            {
                if (--indegree[v] == 0)
                    Q.push(v);
            }
        }
        return counter == numCourses;
    }
};

// dfs (detect cycle)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);

        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false; // cycle
        onpath[node] = visited[node] = true; 
        
        for (int neigh : graph[node]) 
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;

        onpath[node] = false;
        return false;
    }
};