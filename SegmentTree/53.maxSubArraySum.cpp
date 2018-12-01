//LCM(a, b) = (a*b) / GCD(a,b)

#include <vector>
using namespace std;

struct Node
{
    int maxPrefixSum; // same as prefixSum example
    int maxSuffixSum; // reverse
    int sum;          // same as prefixSum
    int maxSubarraySum;
};

class Solution
{
  public:
    int maxSubArray(vector<int> &array)
    {
        this->m_size = array.size();

        m_segmentTree.resize(4 * this->m_size); // safe size

        buildTree(array, 0, m_size - 1, 0);

        return maxSubArrayQuery(0, m_size - 1, 0, m_size - 1, 0).maxSubarraySum;
    }

  private:
    void buildTree(vector<int> &array, int start, int end, int currentIdx)
    {
        if (start == end)
        {
            // leaf node itself
            m_segmentTree[currentIdx].maxPrefixSum = array[start];
            m_segmentTree[currentIdx].maxSuffixSum = array[start];
            m_segmentTree[currentIdx].sum = array[start];
            m_segmentTree[currentIdx].maxSubarraySum = array[start];
        }
        else
        {
            int mid = start + (end - start) / 2;
            buildTree(array, start, mid, 2 * currentIdx + 1);
            buildTree(array, mid + 1, end, 2 * currentIdx + 2);

            m_segmentTree[currentIdx].sum = m_segmentTree[2 * currentIdx + 1].sum + m_segmentTree[2 * currentIdx + 2].sum;
            m_segmentTree[currentIdx].maxPrefixSum = max(m_segmentTree[2 * currentIdx + 1].maxPrefixSum, m_segmentTree[2 * currentIdx + 1].sum + m_segmentTree[2 * currentIdx + 2].maxPrefixSum);
            m_segmentTree[currentIdx].maxSuffixSum = max(m_segmentTree[2 * currentIdx + 2].maxSuffixSum,
                                                         m_segmentTree[2 * currentIdx + 2].sum + m_segmentTree[2 * currentIdx + 1].maxSuffixSum);

            // have to be continues
            m_segmentTree[currentIdx].maxSubarraySum = max(m_segmentTree[2 * currentIdx + 1].maxSubarraySum,
                                                           max(m_segmentTree[2 * currentIdx + 2].maxSubarraySum,
                                                               m_segmentTree[2 * currentIdx + 1].maxSuffixSum +
                                                                   m_segmentTree[2 * currentIdx + 2].maxPrefixSum));
        }
    }

    Node maxSubArrayQuery(int qs, int qe, int arrayStart, int arrayEnd, int currentIdx) // currentIdx --> node in tree
    {
        Node result;

        if (arrayStart > qe || arrayEnd < qs)
            return result;

        // If segment of this node is a part of given
        // range, then return the node of the segment
        if (qs <= arrayStart && qe >= arrayEnd)
            return m_segmentTree[currentIdx];

        int mid = arrayStart + (arrayEnd - arrayStart) / 2;

        if (qe <= mid)
            return maxSubArrayQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);

        if (qs > mid)
            return maxSubArrayQuery(qs, qe, mid, arrayEnd, 2 * currentIdx + 2);

        // If a part of this segment overlaps with
        // the given range
        Node left = maxSubArrayQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);
        Node right = maxSubArrayQuery(qs, qe, mid, arrayEnd, 2 * currentIdx + 2);

        result.sum = left.sum + right.sum;
        result.maxPrefixSum = max(left.maxPrefixSum, left.sum + right.maxPrefixSum);
        result.maxSuffixSum = max(right.maxSuffixSum, right.sum + left.maxSuffixSum);

        // have to be continues
        result.maxSubarraySum = max(left.maxSubarraySum, max(right.maxSubarraySum, left.maxSuffixSum + right.maxPrefixSum));

        // returns the value
        return result;
    }

    vector<Node> m_segmentTree;
    int m_size;
};