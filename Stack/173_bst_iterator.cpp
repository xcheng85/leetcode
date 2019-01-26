/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        push(root); 
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* current =  myStack.top();
        myStack.pop();
        push(current->right);
        return current->val; 
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return myStack.size() != 0;
    }
    
private:
    stack<TreeNode*> myStack;
 
    void push(TreeNode* node){
        while(node){
            myStack.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */