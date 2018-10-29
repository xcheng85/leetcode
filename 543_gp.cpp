class Solution
{
  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int res = depth(root->left) + depth(root->right);
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};