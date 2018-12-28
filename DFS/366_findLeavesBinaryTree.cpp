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
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        else
        {
            vector<vector<int>> leftRes = findLeaves(root->left);
            vector<vector<int>> rightRes = findLeaves(root->right);

            for (int i = 0; i < min(leftRes.size(), rightRes.size()); i++)
            {
                res.push_back(leftRes[i]);
                res[i].insert(res[i].end(), rightRes[i].begin(), rightRes[i].end());
            }
            if (leftRes.size() < rightRes.size())
            {
                for (int i = leftRes.size(); i < rightRes.size(); i++)
                {
                    res.push_back(rightRes[i]);
                }
            }
            else
            {
                for (int i = rightRes.size(); i < leftRes.size(); i++)
                {
                    res.push_back(leftRes[i]);
                }
            }

            res.push_back({root->val});
        }
        return res;
    }
};