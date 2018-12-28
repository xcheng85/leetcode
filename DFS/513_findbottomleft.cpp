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
    int findBottomLeftValue(TreeNode *root)
    {
        return helper(root, 1).second;
    }

    std::pair<int, int> helper(TreeNode *current, int depth)
    {
        if (!current)
        {
            return make_pair(-1, 0);
        }
        else
        {
            std::pair<int, int> left = helper(current->left, depth + 1);
            std::pair<int, int> right = helper(current->right, depth + 1);

            if (left.first != -1 && right.first != -1)
            {
                if (left.first < right.first)
                {
                    return right;
                }
                else
                    return left;
            }
            else if (left.first != -1)
            {
                return left;
            }
            else if (right.first != -1)
            {
                return right;
            }
            else
            {
                return make_pair(depth, current->val);
            }
        }
    }
};