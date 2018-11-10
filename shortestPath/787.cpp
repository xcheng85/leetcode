struct Node
{
    int price;    // distance/price from the source
    int dst;      // current traversed node_id
    int stopLeft; // num Stop left
    Node(int p, int d, int s) : price(p),
                                dst(d),
                                stopLeft(s)
    {
    }
};

class Compare
{
  public:
    bool operator()(Node *lhs, Node *rhs)
    {
        // min on top
        return lhs->price > rhs->price;
    }
};

//SPT (shortest path tree)

class Solution
{
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // cache original graph
        unordered_map<int, unordered_map<int, int>> graph_edges;
        // SPT
        priority_queue<Node *, vector<Node *>, Compare> spt_pq;

        for (auto flight : flights)
        {
            int src = flight[0];
            int dest = flight[1];
            int price = flight[2];

            graph_edges[src][dest] = price;
        }

        // find the source
        spt_pq.push(new Node(0, src, K + 1));
        while (!spt_pq.empty())
        {
            // smallest on top
            Node *tmp = spt_pq.top();
            spt_pq.pop();
            int price = tmp->price;
            int city = tmp->dst;
            int stopLeft = tmp->stopLeft;
            // find the neighboring edges for current source node
            if (city == dst)
                return price;

            if (stopLeft > 0)
            {
                unordered_map<int, int> edges = graph_edges[city];
                for (auto it = edges.begin(); it != edges.end(); it++)
                {
                    int dst_city = it->first;
                    int new_price = it->second;
                    spt_pq.push(new Node(price + new_price, dst_city, stopLeft - 1));
                }
            }
        }

        return -1;
    }
};