#include <vector>

class Solution
{
  public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        if (matrix.empty())
            return 0;

        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;

        // 1d Kodane Algorithm from col [0,0], [0, 1]
        for (int l = 0; l < col; ++l)
        {
            
            vector<int> sums(row, 0);

            for (int r = l; r < col; ++r)
            {
                for (int i = 0; i < row; ++i)
                {
                    sums[i] += matrix[i][r];
                }

                // Find the max subarray no more than K
                set<int> accuSet;
                accuSet.insert(0);  // no larger than k

                int curSum = 0, curMax = INT_MIN;
                for (int sum : sums)
                {
                    curSum += sum;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                
                    if (it != accuSet.end())
                        curMax = std::max(curMax, curSum - *it);
                    accuSet.insert(curSum);
                }
                res = std::max(res, curMax);
            }
        }
        return res;
    }
};