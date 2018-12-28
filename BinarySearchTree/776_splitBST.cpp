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
    vector<TreeNode *> splitBST(TreeNode *root, int V)
    {
        TreeNode *current = root;
        if (!root)
            return {NULL, NULL};

        if (V < root->val)
        {
            vector<TreeNode *> tmp = splitBST(root->left, V);
            root->left = tmp[1];
            return {tmp[0], root};
        }
        else
        {
            vector<TreeNode *> tmp = splitBST(root->right, V);
            root->right = tmp[0];
            return {root, tmp[1]};
        }
    }
};