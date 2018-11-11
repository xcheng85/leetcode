class Solution
{
  public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        TreeNode *dummy = new TreeNode(-1);
        dummy->left = root;
        TreeNode *current = dummy;
        while (current)
        {
            // check if left child node is NULL, move to the right subtree
            if (current->left == NULL)
            {
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
                    rightMost->right = current; // add a SingleThread
                    current = current->left;    // start to traverse left substree
                }
                else
                {
                    // when the entire left tree has finished traversal and current is visited the second time
                    bst_morris_reverse(current->left, rightMost, current, ans);

                    rightMost->right = NULL;
                    current = current->right;
                }
            }
        }

        return ans;
    }

  private:
    void bst_morris_reverse(TreeNode *node, TreeNode *last, TreeNode *end, vector<int> &ans)
    {
        // reverse order
        list<int> cur;
        for (TreeNode *i = node; i != end; i = i->right)
        {
            cur.push_front(i->val);
        }
        ans.insert(ans.end(), cur.begin(), cur.end());
    }
};
