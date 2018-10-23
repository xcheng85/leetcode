// recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        
        if(node1 == NULL && node2 != NULL){
            return false; 
        }
        
        if(node1 != NULL && node2 == NULL){
            return false;
        }
        
        if(node1->val != node2-> val){
            return false; 
        }
        
        return node1->val == node2-> val && helper(node1->left, node2->right) && helper(node1->right, node2->left);
        
    }
};

//iterative
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> bfs;
        bfs.push(root);
        bfs.push(root); 
        
        while(bfs.size() > 0){
            TreeNode* t1 = bfs.front();
            bfs.pop();
            TreeNode* t2 = bfs.front();
            bfs.pop();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            bfs.push(t1->left);
            bfs.push(t2->right);
            bfs.push(t1->right);
            bfs.push(t2->left);
        }
        return true;
    }
};