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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }

    void helper(TreeNode *root, int depth, vector<int> &res)
    {
        if (!root)
            return;
        if (depth + 1 > res.size())
        {
            res.push_back(root->val);
        }
        else
        {
            res[depth] = max(res[depth], root->val);
        }
        helper(root->left, depth + 1, res);
        helper(root->right, depth + 1, res);
    }
};