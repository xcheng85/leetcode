struct SegmentTreeNode
{
    int l, r;
    int k, lazy; // k: book count

    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int l, int r, int k) : l(l),
                                           r(r),
                                           k(k),
                                           lazy(0),
                                           left(nullptr),
                                           right(nullptr)
    {
    }
};

class MyCalendarThree
{
  public:
    MyCalendarThree()
    {
        m_root = new SegmentTreeNode(0, 1000000000, 0);
        m_maxBook = 0;
    }

    int book(int start, int end)
    {
        // + 1
        update(m_root, start, end - 1, 1);
        return m_maxBook;
    }

  private:
    SegmentTreeNode *m_root;
    int m_maxBook;

    void update(SegmentTreeNode *node, int i, int j, int val)
    {
        normalize(node);

        //cout << i << " " << node->r  << endl;
        if (i > j || node == nullptr || i > node->r || j < node->l)
            return;

        //cout << i << " " << j << " " << val << endl;
        if (i <= node->l && node->r <= j)
        {
            node->lazy = val;
            //cout << val << endl;
            normalize(node);
            return;
        }

        update(node->left, i, j, val);
        update(node->right, i, j, val);

        node->k = max(node->left->k, node->right->k);
        m_maxBook = max(node->k, m_maxBook);
        //cout << node->k << endl;
    }

    void normalize(SegmentTreeNode *node)
    {
        if (node->lazy > 0)
            node->k += node->lazy;

        // until node range is 1 [a, a]
        if (node->l < node->r)
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                int m = node->l + (node->r - node->l) / 2;
                //cout << node->l << " " << m << endl;
                //cout << m + 1 << " " << node->r << endl;
                node->left = new SegmentTreeNode(node->l, m, node->k);
                node->right = new SegmentTreeNode(m + 1, node->r, node->k);
            }
            else if (node->lazy > 0)
            {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }
        }

        node->lazy = 0;
    }
};
