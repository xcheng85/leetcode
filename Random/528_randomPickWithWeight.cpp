#include <vector>

class Solution
{
  private:
    vector<int> m_prefixSum;

  public:
    Solution(vector<int> w)
    {
        int weight = 0;
        m_prefixSum.resize(w.size());

        for (int i = 0; i < w.size(); i++)
        {
            weight += w[i];
            m_prefixSum[i] = weight;
        }
    }

    int pickIndex()
    {
        int m = m_prefixSum.back();
        int r = rand() % m;

        // binary search
        int lo = 0, hi = m_prefixSum.size() - 1;
        while (lo != hi)
        {
            int mid = (lo + hi) / 2;
            if (r >= m_prefixSum[mid])
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};