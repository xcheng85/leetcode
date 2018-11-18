// 1. un-optimized
// N nodes with N edges with one redundunt edges
class Solution
{
  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // parent table
        int num_nodes = edges.size();

        vector<int> parent(num_nodes, -1); // initialized with no parent

        // iterate edges to find out parent
        for (auto &edge : edges)
        {
            int srcNode = edge[0];
            int destNode = edge[1];

            int srcNodeParent = findParentNode(parent, srcNode);
            int destNodeParent = findParentNode(parent, destNode);

            // initially set parentNode to itself and then union
            if (srcNodeParent == destNodeParent)
            {
                return edge;
            }
            else
            {
                // update parent table
                Union(parent, srcNodeParent, destNodeParent);
            }
        }
    }

  private:
    void Union(vector<int> &parent, int srcNode, int destNode)
    {
        int p1 = findParentNode(parent, srcNode);
        int p2 = findParentNode(parent, destNode);

        if (p1 != p2)
        {
            parent[p1] = p2;
        }
    }

    int findParentNode(vector<int> &parent, int currentNodeId)
    {
        if (parent[currentNodeId] != -1)
        {
            return findParentNode(parent, parent[currentNodeId]);
        }
        else
        {
            return currentNodeId;
        }
    }
};