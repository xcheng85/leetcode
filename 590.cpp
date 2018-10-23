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
    vector<int> postorder(Node* root) {
        stack<Node*> myStack; 
        
        myStack.push(root);
        vector<int> result; 
        if(root==NULL) return {};
        while(myStack.size() != 0){
            Node* top = myStack.top();
            result.push_back(top->val);
            myStack.pop(); 
            for(int i = 0; i < top->children.size(); i++){
                myStack.push(top->children[i]);
            }
        }
        reverse(result.begin(), result.end());
        return result; 
    }
};