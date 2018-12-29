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
    int closestValue(TreeNode* root, double target) {
        return helper(root, target).first;  
    }
    
    pair<int, float> helper(TreeNode* node, double target){
        float diff = abs(node->val - target); 
        int res = node->val; 
        
        if(node->val < target){
            if(node->right){
                pair<int, float> tmp = helper(node->right, target); 
                if(tmp.second < diff){
                    res = tmp.first;
                    diff = tmp.second; 
                }
            }
        }
        if(node->val > target){
            if(node->left){
                pair<int, float> tmp = helper(node->left, target); 
                if(tmp.second < diff){
                    res = tmp.first;
                    diff = tmp.second; 
                }
            }
        }
        return make_pair(res, diff); 
    }
};