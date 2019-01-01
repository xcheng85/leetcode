/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return NULL;

        int maxIndx = -1;
        int maxVal = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            if (nums[k] > maxVal)
            {
                maxVal = nums[k];
                maxIndx = k;
            }
        }

        TreeNode *left = helper(nums, i, maxIndx - 1);
        TreeNode *right = helper(nums, maxIndx + 1, j);
        TreeNode *cur = new TreeNode(maxVal);
        cur->left = left;
        cur->right = right;

        return cur;
    }
};