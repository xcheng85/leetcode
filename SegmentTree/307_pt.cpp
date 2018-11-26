#include <vector>
using namespace std;

struct SegmentTreeNode
{
    int start, end, sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int a, int b) : start(a), end(b), sum(0), left(nullptr), right(nullptr) {}
};

class NumArray
{
  public:
    NumArray(vector<int> nums)
    {
        int n = nums.size();
        root = buildTree(nums, 0, n - 1);
    }

    void update(int i, int val)
    {
        updateTree(i, val, root);
    }

    int sumRange(int i, int j)
    {
        return queryTreeByRange(i, j, root);
    }

  private:
    SegmentTreeNode *buildTree(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end)
        {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int updateTree(int i, int val, SegmentTreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int diff;
        // find the exact node
        if (root->start == i && root->end == i)
        {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if (i > mid)
        {
            diff = updateTree(i, val, root->right);
        }
        else
        {
            diff = updateTree(i, val, root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }

    int queryTreeByRange(int i, int j, SegmentTreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->start == i && root->end == j)
            return root->sum;
        int mid = (root->start + root->end) / 2;
        if (i > mid)
            return queryTreeByRange(i, j, root->right);
        if (j <= mid)
            return queryTreeByRange(i, j, root->left);
        return queryTreeByRange(i, mid, root->left) + queryTreeByRange(mid + 1, j, root->right);
    }

    SegmentTreeNode *root;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */