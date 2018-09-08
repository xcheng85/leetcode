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
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return root; 
        }
        
        TreeNode* left = root->left; 
        TreeNode* right = root->right; 
        
        root->left = NULL; 
        root->right = NULL; 
        
        TreeNode* newRoot = increasingBST(left); 
        
        TreeNode* newRight = increasingBST(right); 
        
        root->right = newRight; 
        if(newRoot == NULL){
            return root; 
        }
        
        TreeNode* lastRight = newRoot; 
        while(lastRight && lastRight->right){
            lastRight = lastRight->right; 
        }
        lastRight -> right = root;
        return newRoot; 
    }
};