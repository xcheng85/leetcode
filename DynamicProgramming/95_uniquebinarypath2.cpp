class Solution
{
  public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n <= 0)
            return {};
        return constructTrees(1, n);
    }
    // recursive
    vector<TreeNode *> constructTrees(int start, int end)
    {
        vector<TreeNode *> list;

        /*  if start > end   then subtree will be empty so returning NULL 
        in the list */
        if (start > end)
        {
            list.push_back(NULL);
            return list;
        }

        /*  iterating through all values from start to end  for constructing\ 
        left and right subtree recursively  */
        for (int i = start; i <= end; i++)
        {
            /*  constructing left subtree   */
            vector<TreeNode *> leftSubtree = constructTrees(start, i - 1);

            /*  constructing right subtree  */
            vector<TreeNode *> rightSubtree = constructTrees(i + 1, end);

            /*  now looping through all left and right subtrees and connecting 
            them to ith root  below  */
            for (int j = 0; j < leftSubtree.size(); j++)
            {
                TreeNode *left = leftSubtree[j];
                for (int k = 0; k < rightSubtree.size(); k++)
                {
                    TreeNode *right = rightSubtree[k];
                    TreeNode *node = new TreeNode(i); // making value i as root
                    node->left = left;                // connect left subtree
                    node->right = right;              // connect right subtree
                    list.push_back(node);             // add this tree to list
                }
            }
        }
        return list;
    }
};