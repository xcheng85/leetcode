class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        // it is a BST, there is no way the min distance is happened between father and child

        int res = numeric_limits<int>::max();
        TreeNode *prev = nullptr;
        helper(root,prev,res);
        return res;
    }
    
    void helper(TreeNode* root, TreeNode* &prev, int &res){
        if(root){
            helper(root->left,prev,res);
            if(prev!=nullptr)
                res = min(res, root->val-prev->val);
            prev = root;
            helper(root->right,prev,res);
        }
        
    }
};