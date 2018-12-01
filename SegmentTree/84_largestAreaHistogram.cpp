// divide and conquer
// find the minimal val
// max(left, minimal * num , rightside of minimal)

// based on histogram array, build segment tree of histogram height, store the min val
//

#include <vector>
using namespace std;

struct SegmentTreeNode
{
    // state of node is minimal value in this range
    int minValIndex; // index of minimal value in this range
    int start;
    int end;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int i, int s, int e) : minValIndex(i),
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
    int largestRectangleArea(vector<int> &heights)
    {
        m_size = heights.size();
        if (m_size == 0)
            return 0;
        m_root = this->buildTree(heights, 0, m_size - 1);
        return getMaxAreaRec(heights, 0, m_size - 1);
    }

  private:
    SegmentTreeNode *buildTree(vector<int> &heights, int start, int end)
    {
        if (start == end)
        {
            return new SegmentTreeNode(start, start, end);
        }
        else
        {
            int mid = start + (end - start) / 2;
            SegmentTreeNode *left = buildTree(heights, start, mid);
            SegmentTreeNode *right = buildTree(heights, mid + 1, end);

            SegmentTreeNode *root = NULL;
            if (heights[left->minValIndex] < heights[right->minValIndex])
            {
                root = new SegmentTreeNode(left->minValIndex, start, end);
            }
            else
            {
                root = new SegmentTreeNode(right->minValIndex, start, end);
            }

            root->left = left;
            root->right = right;

            return root;
        }
    }

    int getMaxAreaRec(vector<int> &heights, int start, int end)
    {
        if (start > end)
            return INT_MIN;
        if (start == end)
            return heights[start];

        // Find index of the minimum value in given range
        // This takes O(Logn)time
        int m = rangeMinimalQuery(heights, this->m_root, start, end);

        /* Return maximum of following three possible cases 
       a) Maximum area in Left of min value (not including the min) 
       a) Maximum area in right of min value (not including the min) 
       c) Maximum area including min */
        return max(getMaxAreaRec(heights, start, m - 1),
                   max(getMaxAreaRec(heights, m + 1, end),
                       (end - start + 1) * (heights[m])));
    }

    // Return index of minimum element in range from index qs (quey start) to
    // qe (query end).  It mainly uses RMQUtil()
    int rangeMinimalQuery(vector<int> &heights, SegmentTreeNode *node, int qs, int qe)
    {

        int start = node->start;
        int end = node->end;

        if (qs <= start && qe >= end)
            return node->minValIndex;
        if (qs > end || qe < start)
            return -1;

        int minLeft = rangeMinimalQuery(heights, node->left, qs, qe);
        int minRight = rangeMinimalQuery(heights, node->right, qs, qe);

        if (minLeft == -1)
        {
            return minRight;
        }
        if (minRight == -1)
            return minLeft;

        return heights[minLeft] < heights[minRight] ? minLeft : minRight;
    }

    SegmentTreeNode *m_root;
    int m_size;
};