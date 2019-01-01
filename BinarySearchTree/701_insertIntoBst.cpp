/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
			TreeNode *newNode = new TreeNode(val);
			return newNode;
		}
		if (val < root->val) {
			root->left = insertIntoBST(root->left, val);
		}
		else {
			root->right = insertIntoBST(root->right, val);
		}
		return root;
    }
};

// iterative

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(root == nullptr) 
           return new TreeNode(val);
        
        TreeNode* cur = root;
        while(true) {
            if(cur->val <= val) {
                if(cur->right != nullptr) cur = cur->right;
                else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if(cur->left != nullptr) cur = cur->left;
                else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};