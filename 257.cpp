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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result; 
        
        dfs(root, NULL, "", result); 
        
        return result; 
    }
    
    void dfs(TreeNode* current, TreeNode* prev, string tmp, vector<string>& result){
        cout << tmp << endl;  
        if(current == NULL){
            return;
        }
        if(prev != NULL){
            tmp += "->";  
        }
        tmp += to_string(current->val); 
        if(current->left == NULL && current->right == NULL){
            result.push_back(tmp);
        }else{
            if(current->left!=NULL)
                dfs(current->left, current, tmp, result); 
            if(current->right!=NULL)
                dfs(current->right, current, tmp, result); 
        }
    }
};