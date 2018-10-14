// 1. recursive


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q != NULL){
            return false;
        }
        if(p != NULL && q == NULL){
            return false;
        }
        if(q == NULL && p == NULL){
            return true;
        }
        
        if(p->val != q->val){
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
        
    }
};

// 2.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // preorder traversal
        stack<TreeNode*> stack_p;
        stack<TreeNode*> stack_q;
        if(p)   stack_p.push(p);
        if(q)   stack_q.push(q);

        while(!stack_p.empty() && !stack_q.empty()){
            TreeNode* cur_p=stack_p.top();
            TreeNode* cur_q=stack_q.top();

            stack_p.pop();
            stack_q.pop();

            if(cur_p->val!=cur_q->val) return false;

            if(cur_p->left) stack_p.push(cur_p->left);
            if(cur_q->left) stack_q.push(cur_q->left);

            if(stack_p.size() != stack_q.size())    return false;

            if(cur_p->right) stack_p.push(cur_p->right);
            if(cur_q->right) stack_q.push(cur_q->right);

            if(stack_p.size() != stack_q.size())    return false;
        }

        return stack_p.size() == stack_q.size();
    }
};