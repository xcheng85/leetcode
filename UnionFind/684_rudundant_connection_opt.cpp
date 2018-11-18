// 1. path compression + union rank
// N nodes with N edges with one redundunt edges

struct subset
{
    int parent;
    int rank;

    subset(int p = 0, int r = 0) : parent(p), rank(r)
    {
    }
};

class Solution
{
  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // parent table
        int num_nodes = edges.size();

        vector<subset> subsets;
        subsets.resize(num_nodes);

        for (int i = 0; i < num_nodes; i++)
        {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        // iterate edges to find out parent
        for (auto &edge : edges)
        {
            // be careful !!!
            int srcNode = edge[0] - 1;
            int destNode = edge[1] - 1;

            int srcNodeParent = findParentNode(subsets, srcNode);
            int destNodeParent = findParentNode(subsets, destNode);

            // initially set parentNode to itself and then union
            if (srcNodeParent == destNodeParent)
            {
                return edge;
            }
            else
            {
                // update parent table
                Union(subsets, srcNodeParent, destNodeParent);
            }
        }
    }

  private:
    void Union(vector<subset> &subsets, int srcNode, int destNode)
    {
        int p1 = findParentNode(subsets, srcNode);
        int p2 = findParentNode(subsets, destNode);

        // compare by rank
        if (subsets[p1].rank < subsets[p2].rank)
        {
            subsets[p1].parent = p2;
        }
        else if (subsets[p1].rank > subsets[p2].rank)
        {
            subsets[p2].parent = p1;
        }
        else
        {
            subsets[p2].parent = p1;
            subsets[p1].rank++;
        }
    }
    // path compression
    int findParentNode(vector<subset> &subsets, int currentNodeId)
    {
        if (subsets[currentNodeId].parent != currentNodeId)
            subsets[currentNodeId].parent = findParentNode(subsets, subsets[currentNodeId].parent);

        return subsets[currentNodeId].parent;
    }
};