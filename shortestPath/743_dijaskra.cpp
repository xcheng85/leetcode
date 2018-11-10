struct Node // spt
{
    int delay; // delay/distance/price from the source
    int dst;   // current traversed node_id
    Node(int p, int d) : delay(p), dst(d)
    {
    }
};

class Compare
{
  public:
    bool operator()(Node *lhs, Node *rhs)
    {
        // min on top
        return lhs->delay > rhs->delay;
    }
};

class Solution
{
  public:
    // N nodes
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        // cache original graph
        unordered_map<int, unordered_map<int, int>> graph_edges;
        // SPT
        priority_queue<Node *, vector<Node *>, Compare> spt_pq;
        // Secrect ignore shorter distance so we can get the longest distance in the end
        unordered_map<int, int> distanceMap;
        distanceMap[K] = 0;

        for (auto time : times)
        {
            int src = time[0];
            int dst = time[1];
            int delay = time[2];

            graph_edges[src][dst] = delay;
        }

        spt_pq.push(new Node(0, K));

        while (!spt_pq.empty())
        {
            Node *tmp = spt_pq.top();
            spt_pq.pop();

            int delay = tmp->delay;
            int id = tmp->dst;

            // Ignore processed nodes
            if (distanceMap.find(id) != distanceMap.end() && distanceMap[id] < delay)
            {
                continue;
            }

            unordered_map<int, int> neighboringEdges = graph_edges[id];
            for (auto it = neighboringEdges.begin(); it != neighboringEdges.end(); it++)
            {
                int dst = it->first;
                int newDistance = delay + it->second;
                if (distanceMap.find(dst) != distanceMap.end() && distanceMap[dst] <= newDistance)
                {
                    continue;
                }
                distanceMap[dst] = newDistance;
                spt_pq.push(new Node(newDistance, dst));
            }
        }

        int maxDelay = INT_MIN;
        for (auto it = distanceMap.begin(); it != distanceMap.end(); it++)
        {
            maxDelay = max(maxDelay, it->second);
        }

        return distanceMap.size() == N ? maxDelay : -1;
    }
};
