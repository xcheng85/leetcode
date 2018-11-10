// difference between Dijastrka and bellman-ford algorithm

// bellman-ford can solve negative weight 
// bellman can check graph cycle

// difference time complexity
// Dijask: O(VLogV + E)
// bellman-ford O(VE)

class Solution
{
  public:
    // N nodes
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        //step one inialize all node to be positive infinite except source node K
        vector<int> node(N, INT_MAX); 
        node[K-1] = 0; 

        // N - 1 times because at most N-1 edges
        for(int i = 0; i < N - 1; i++){
            for(auto time: times){
                int src = time[0] - 1; 
                int dst = time[1] - 1; 
                int delay = time[2]; 

                if(node[src] != INT_MAX){
                    node[dst] = min(node[dst], node[src] + delay); 
                }
            }
        }

        // get the max value
        int maxDelay = INT_MIN; 
        for(int i = 0; i < N; i++){
            if(node[i] == INT_MAX)
                return -1; 
            maxDelay = max(maxDelay, node[i]); 
        }

        return maxDelay; 
    }
};
