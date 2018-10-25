/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// in-order traversal and increasing array

/* Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
 */

class Solution
{
  public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *current = root;

        stack<TreeNode *> dfs;
        vector<int> increasingArray;

        while (current != NULL || dfs.empty() == false)
        {
            if (current)
            {
                while (current)
                {
                    dfs.push(current);
                    current = current->left;
                }
            }
            else
            {
                TreeNode *tmp = dfs.top();
                dfs.pop();
                increasingArray.push_back(tmp->val);
                current = tmp->right;
            }
        }

        for (int i = 1; i < increasingArray.size(); i++)
        {
            if (increasingArray[i] <= increasingArray[i - 1])
                return false;
        }

        return true;
    }
};