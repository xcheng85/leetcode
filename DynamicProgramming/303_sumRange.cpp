// imutable : difference with segment tree

struct Node
{
    int sum;
    Node(int sum = -1) : sum(sum)
    {
    }
};

class NumArray
{
  public:
    NumArray(vector<int> nums)
    {
        m_size = nums.size();

        if (m_size > 0)
        {

            m_segmentTree.resize(4 * this->m_size); // safe size

            buildTree(nums, 0, m_size - 1, 0);
        }
    }

    int sumRange(int i, int j)
    {
        return rangeSumQuery(i, j, 0, m_size - 1, 0);
    }

  private:
    void buildTree(vector<int> &array, int start, int end, int currentIdx)
    {
        if (start == end)
        {
            // leaf node itself
            m_segmentTree[currentIdx].sum = array[start];
            return;
        }
        else
        {
            int mid = start + (end - start) / 2;
            buildTree(array, start, mid, 2 * currentIdx + 1);
            buildTree(array, mid + 1, end, 2 * currentIdx + 2);

            m_segmentTree[currentIdx].sum = m_segmentTree[2 * currentIdx + 1].sum + m_segmentTree[2 * currentIdx + 2].sum;
        }
    }

    int rangeSumQuery(int qs, int qe, int arrayStart, int arrayEnd, int currentIdx) // currentIdx --> node in tree
    {
        if (arrayStart > qe || arrayEnd < qs)
            return 0;

        // If segment of this node is a part of given
        // range, then return the node of the segment
        if (qs <= arrayStart && qe >= arrayEnd)
            return m_segmentTree[currentIdx].sum;

        int mid = arrayStart + (arrayEnd - arrayStart) / 2;

        if (qe <= mid)
            return rangeSumQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);

        if (qs > mid)
        {
            return rangeSumQuery(qs, qe, mid + 1, arrayEnd, 2 * currentIdx + 2);
        }

        // If a part of this segment overlaps with
        // the given range
        return rangeSumQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1) + rangeSumQuery(qs, qe, mid + 1, arrayEnd, 2 * currentIdx + 2);
    }

    vector<Node> m_segmentTree;
    int m_size;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */