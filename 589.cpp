/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> myStack; 
        
        myStack.push(root);
        vector<int> result; 
        if(root==NULL) return {};
        while(myStack.size() != 0){
            Node* top = myStack.top();
            result.push_back(top->val);
            myStack.pop(); 
            for(int i = top->children.size() - 1; i >= 0; i--){
                myStack.push(top->children[i]);
            }
        }
        return result; 
    }
};