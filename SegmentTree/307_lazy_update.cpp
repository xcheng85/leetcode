class NumArray
{
  public:
    NumArray(vector<int> nums)
    {
        int n = nums.size();
        if (n > 0)
        {
            m_segmentTree.resize(4 * n); // safe size
            buildSegTree(nums, 0, 0, n - 1);
        }

        m_nums = n;
    }

    void update(int i, int val)
    {
        updateValSegTree(0, 0, m_nums - 1, i, val);
    }

    int sumRange(int i, int j)
    {
        return querySegTree(0, 0, m_nums - 1, i, j);
    }

  private:
    vector<int> m_segmentTree;
    int m_nums;

  private:
    void buildSegTree(vector<int> &arr, int treeIndex, int lo, int hi)
    {
        if (lo == hi)
        { // leaf node. store value in node.
            m_segmentTree[treeIndex] = arr[lo];
            return;
        }

        int mid = lo + (hi - lo) / 2; // recurse deeper for children.
        buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
        buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);

        // merge build results
        m_segmentTree[treeIndex] = m_segmentTree[2 * treeIndex + 1] + m_segmentTree[2 * treeIndex + 2];
    }

    void updateValSegTree(int treeIndex, int lo, int hi, int arrIndex, int val)
    {
        if (lo == hi)
        { // leaf node. update element.
            m_segmentTree[treeIndex] = val;
            return;
        }

        int mid = lo + (hi - lo) / 2; // recurse deeper for appropriate child

        if (arrIndex > mid)
            updateValSegTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
        else if (arrIndex <= mid)
            updateValSegTree(2 * treeIndex + 1, lo, mid, arrIndex, val);

        // merge updates
        m_segmentTree[treeIndex] = m_segmentTree[2 * treeIndex + 1] + m_segmentTree[2 * treeIndex + 2];
    }

    int querySegTree(int treeIndex, int lo, int hi, int i, int j)
    {
        // query for arr[i..j]
        if (lo > j || hi < i) // segment completely outside range
            return 0;         // represents a null node

        if (i <= lo && j >= hi) // segment completely inside range
            return m_segmentTree[treeIndex];

        int mid = lo + (hi - lo) / 2; // partial overlap of current segment and queried range. Recurse deeper.

        if (i > mid)
            return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
        else if (j <= mid)
            return querySegTree(2 * treeIndex + 1, lo, mid, i, j);

        int leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
        int rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

        // merge query results
        return leftQuery + rightQuery;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */