// shortest path from one source to all destination
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    // N nodes
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        // initialized 2d array with positive infinity
        vector<vector<int>> ansMatrix(N, vector<int>(N, INT_MAX));

        // diagonal elements is 0. distance to itself
        for (int i = 0; i < N; i++)
        {
            ansMatrix[i][i] = 0;
        }

        // from neighboring elements
        for (auto &time : times)
        {
            int src = time[0] - 1; // label start from 1
            int dest = time[1] - 1;
            int delay = time[2];

            ansMatrix[src][dest] = delay;
        }

        // interim node
        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (ansMatrix[i][k] != INT_MAX && ansMatrix[k][j] != INT_MAX && ansMatrix[i][j] > ansMatrix[i][k] + ansMatrix[k][j] ){
                     
                        ansMatrix[i][j] = ansMatrix[i][k] + ansMatrix[k][j];
                        //std::cout << i << " " << j << " " << ansMatrix[i][j] << endl; 
                    }
                }
            }
        }

        // if there is one source node cannot be reached by source node K, means impossible
        int maxDelay = INT_MIN; 
        for(int i = 0; i < N; i++){
            if(ansMatrix[K - 1][i] == INT_MAX)
                return -1; 
            maxDelay = max(maxDelay, ansMatrix[K - 1][i]);
        }

        return maxDelay; 
    }
};