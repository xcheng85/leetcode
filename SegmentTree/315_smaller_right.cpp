/* Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
 */

#include <vector>
using namespace std;

// min = 1, 6
// 3
struct SegmentTreeNode
{
    int lowerBound, higherBound, cnt;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int a, int b) : lowerBound(a),
                                    higherBound(b),
                                    cnt(0),
                                    left(nullptr),
                                    right(nullptr)
    {
    }
};

class Solution
{
  public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (auto &num : nums)
        {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        m_root = buildTree(nums, minVal, maxVal);
        vector<int> ans;
        ans.resize(n);

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = queryTreeByRange(minVal, nums[i] - 1, m_root);
            updateTree(nums[i], m_root);
        }

        return ans;
    }

  private:
    SegmentTreeNode *buildTree(vector<int> &nums, int minVal, int maxVal)
    {
        if (minVal > maxVal)
            return nullptr;

        SegmentTreeNode *root = new SegmentTreeNode(minVal, maxVal);
        if (minVal == maxVal)
        {
            return root;
        }
        int mid = minVal + (maxVal - minVal) / 2;
        root->left = buildTree(nums, minVal, mid);
        root->right = buildTree(nums, mid + 1, maxVal);
        return root;
    }

    void updateTree(int val, SegmentTreeNode *root)
    {
        if (root == nullptr)
            return;

        if (val < root->lowerBound || val > root->higherBound)
            return;

        if (root->lowerBound == val && root->higherBound == val)
        {
            root->cnt++;
            return;
        }
        int mid = root->lowerBound + (root->higherBound - root->lowerBound) / 2;
        if (val > mid)
        {
            updateTree(val, root->right);
        }
        else
        {
            updateTree(val, root->left);
        }
        root->cnt = 0;
        if (root->left)
            root->cnt = root->left->cnt;
        if (root->right)
            root->cnt += root->right->cnt;
    }

    int queryTreeByRange(int lowerBound, int higherBound, SegmentTreeNode *root)
    {

        if (root == nullptr)
            return 0;
        if (lowerBound <= root->lowerBound && higherBound >= root->higherBound)
            return root->cnt;

        int mid = root->lowerBound + (root->higherBound - root->lowerBound) / 2;
        if (lowerBound > mid)
            return queryTreeByRange(lowerBound, higherBound, root->right);
        if (higherBound <= mid)
            return queryTreeByRange(lowerBound, higherBound, root->left);

        return queryTreeByRange(lowerBound, mid, root->left) + queryTreeByRange(mid + 1, higherBound, root->right);
    }

    SegmentTreeNode *m_root;
};
