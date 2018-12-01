//LCM(a, b) = (a*b) / GCD(a,b)

#include <vector>
using namespace std;

class Solution
{
  public:
    int queryGCDRange(vector<int> &array, int l, int r)
    {
        this->m_size = array.size();

        m_segmentTree.resize(4 * this->m_size); // safe size

        buildTree(array, 0, m_size - 1, 0);

        return gcdQuery(l, r, 0, m_size - 1, 0);
    }

  private:
    void buildTree(vector<int> &array, int start, int end, int currentIdx)
    {
        if (start == end)
        {
            // leaf node itself
            m_segmentTree[currentIdx] = array[start];
            return;
        }
        else
        {
            int mid = start + (end - start) / 2;
            buildTree(array, start, mid, 2 * currentIdx + 1);
            buildTree(array, mid + 1, end, 2 * currentIdx + 2);

            m_segmentTree[currentIdx] = this->gcd(m_segmentTree[2 * currentIdx + 1], m_segmentTree[2 * currentIdx + 2]);
        }
    }

    int gcdQuery(int qs, int qe, int arrayStart, int arrayEnd, int currentIdx) // currentIdx --> node in tree
    {
        if (arrayStart > qe || arrayEnd < qs)
            return 0;
        if (qs <= arrayStart && qe >= arrayEnd)
            return m_segmentTree[currentIdx];
        int mid = arrayStart + (arrayEnd - arrayStart) / 2;
        return gcd(gcdQuery(qs, qe, arrayStart, mid, currentIdx * 2 + 1),
                   gcdQuery(qs, qe, mid + 1, arrayEnd, currentIdx * 2 + 2));
    }

    // Function to return gcd of a and b
    // euler algorithm https://en.wikipedia.org/wiki/Greatest_common_divisor
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    vector<int> m_segmentTree;
    int m_size;
};