//LCM(a, b) = (a*b) / GCD(a,b)

#include <vector>
using namespace std;

struct Node
{
    int sum;
    int maxPrefixSum;

    Node(int sum = -1, int maxPrefixSum = -1) : sum(sum), maxPrefixSum(maxPrefixSum)
    {
    }
};

class Solution
{
  public:
    int maxPrefixSum(vector<int> &array, int l, int r)
    {
        this->m_size = array.size();

        m_segmentTree.resize(4 * this->m_size); // safe size

        buildTree(array, 0, m_size - 1, 0);

        return prefixQuery(l, r, 0, m_size - 1, 0).maxPrefixSum;
    }

  private:
    void buildTree(vector<int> &array, int start, int end, int currentIdx)
    {
        if (start == end)
        {
            // leaf node itself
            m_segmentTree[currentIdx].maxPrefixSum = array[start];
            m_segmentTree[currentIdx].sum = array[start];
            return;
        }
        else
        {
            int mid = start + (end - start) / 2;
            buildTree(array, start, mid, 2 * currentIdx + 1);
            buildTree(array, mid + 1, end, 2 * currentIdx + 2);

            m_segmentTree[currentIdx].sum = m_segmentTree[2 * currentIdx + 1].sum + m_segmentTree[2 * currentIdx + 2].sum;
            m_segmentTree[currentIdx].maxPrefixSum = max(m_segmentTree[2 * currentIdx + 1].maxPrefixSum,
                                                         m_segmentTree[2 * currentIdx + 1].sum + m_segmentTree[2 * currentIdx + 2].maxPrefixSum);
        }
    }

    Node prefixQuery(int qs, int qe, int arrayStart, int arrayEnd, int currentIdx) // currentIdx --> node in tree
    {
        Node result;
        result.sum = result.maxPrefixSum = -1;

        if (arrayStart > qe || arrayEnd < qs)
            return result;

        // If segment of this node is a part of given
        // range, then return the node of the segment
        if (qs <= arrayStart && qe >= arrayEnd)
            return m_segmentTree[currentIdx];

        int mid = arrayStart + (arrayEnd - arrayStart) / 2;

        if (qe <= mid)
            return prefixQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);

        if (qs > mid)
            return prefixQuery(qs, qe, mid, arrayEnd, 2 * currentIdx + 2);

        // If a part of this segment overlaps with
        // the given range
        Node left = prefixQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);
        Node right = prefixQuery(qs, qe, mid, arrayEnd, 2 * currentIdx + 2);

        // adds the sum of the left and right
        // segment
        result.sum = left.sum + right.sum;

        // stores the max of prefix-sum
        result.maxPrefixSum = max(left.maxPrefixSum, left.sum + right.maxPrefixSum);

        // returns the value
        return result;
    }

    // Function to return gcd of a and b
    // euler algorithm https://en.wikipedia.org/wiki/Greatest_common_divisor
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    vector<Node> m_segmentTree;
    int m_size;
};