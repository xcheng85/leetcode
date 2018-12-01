//LCM(a, b) = (a*b) / GCD(a,b)

#include <vector>
using namespace std;

struct SegmentTreeNode
{
    // state of node is minimal value in this range
    int lcm; // lcm in this range
    int start;
    int end;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int lcm, int s, int e) : lcm(lcm),
                                             start(s),
                                             end(e),
                                             left(nullptr),
                                             right(nullptr)
    {
        }
};

class Solution
{
  public:
    int queryLCMRange(vector<int> &array, int l, int r)
    {
        m_size = array.size();
        if (m_size == 0)
            return 0;
        m_root = this->buildTree(array, 0, m_size - 1);
        return this->lcmQuery(m_root, l, r);
    }

  private:
    SegmentTreeNode *buildTree(vector<int> &heights, int start, int end)
    {
        if (start == end)
        {
            // leaf node itself
            return new SegmentTreeNode(start, start, end);
        }
        else
        {
            int mid = start + (end - start) / 2;
            SegmentTreeNode *left = buildTree(heights, start, mid);
            SegmentTreeNode *right = buildTree(heights, mid + 1, end);

            SegmentTreeNode *root = new SegmentTreeNode(this->lcm(left->lcm, right->lcm), start, end);
            root->left = left;
            root->right = right;

            return root;
        }
    }

    int lcmQuery(SegmentTreeNode *node, int qs, int qe)
    {

        int start = node->start;
        int end = node->end;

        if (qs <= start && qe >= end)
            return node->lcm;
        if (qs > end || qe < start)
            return 1;

        int mid = start + (end - start) / 2;
        int lcm_left = lcmQuery(node->left, qs, mid);
        int lcm_right = lcmQuery(node->right, mid + 1, qe);

        return this->lcm(lcm_left, lcm_right);
    }

    // Function to return gcd of a and b
    // euler algorithm https://en.wikipedia.org/wiki/Greatest_common_divisor
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    //utility function to find lcm
    int lcm(int a, int b)
    {
        return a * b / gcd(a, b);
    }

    SegmentTreeNode *m_root;
    int m_size;
};