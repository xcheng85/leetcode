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
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> result;

        TreeNode *current = root;

        stack<TreeNode *> dfs;

        while (current != NULL || dfs.empty() == false)
        {
            if (current != NULL)
            {
                while (current != NULL)
                {
                    dfs.push(current);
                    current = current->left;
                }
            }
            else
            {
                TreeNode *tmp = dfs.top();
                dfs.pop();
                result.push_back(tmp->val);
                if (tmp->right != NULL)
                {
                    current = tmp->right;
                }
            }
        }

        return result;
    }
};