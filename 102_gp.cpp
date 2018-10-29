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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> result;

        queue<TreeNode *> current;
        queue<TreeNode *> next;

        if (root != NULL)
            current.push(root);
        vector<int> levelResult;
        while (current.empty() == false)
        {

            TreeNode *tmp = current.front();
            current.pop();
            levelResult.push_back(tmp->val);

            if (tmp->left)
            {
                next.push(tmp->left);
            }

            if (tmp->right)
            {
                next.push(tmp->right);
            }

            if (current.empty())
            {
                result.push_back(levelResult);
                levelResult.clear();
                current = next;
                next = queue<TreeNode *>();
            }
        }

        return result;
    }
};