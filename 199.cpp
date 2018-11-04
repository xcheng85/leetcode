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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        
        queue<TreeNode*> bfs; 
        
        if(root)
            bfs.push(root); 
        
        while(!bfs.empty()){
            
            int num = bfs.size(); 
            for(int i = 0; i < num; i++){
                
                TreeNode* tmp = bfs.front(); 
                bfs.pop(); 
                if(i == num-1)
                    ans.push_back(tmp->val);
                
                if(tmp->left){
                    bfs.push(tmp->left);
                }   
                
                if(tmp->right){
                    bfs.push(tmp->right); 
                }
            }
        }
        
        return ans; 
    }
};