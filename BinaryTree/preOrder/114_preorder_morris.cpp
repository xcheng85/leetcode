class Solution
{
  public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        TreeNode *current = root;
        while (current)
        {
            // check if left child node is NULL, move to the right subtree
            if (current->left == NULL)
            {
                ans.push_back(current->val);
                current = current->right;
            }
            else
            {
                // find the rightmost node and then add the link from that node to the current parent node
                TreeNode *rightMost = current->left;
                while (rightMost->right != NULL && rightMost->right != current) // If
                    rightMost = rightMost->right;

                if (rightMost->right == NULL)
                {
                    // only difference from preorder and inorder
                    ans.push_back(current->val); // first time visit current
                    rightMost->right = current; // add a SingleThread
                    current = current->left;    // start to traverse left substree
                }
                else
                {
                    // when the entire left tree has finished traversal and current is visited the second time
                    rightMost->right = NULL;
                    current = current->right;
                }
            }
        }

        return ans;
    }
};