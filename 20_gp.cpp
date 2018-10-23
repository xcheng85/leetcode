class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                myStack.push(s[i]);
            }else{
                if(myStack.size() == 0){
                    return false;
                }
                char topElement = myStack.top();
                if(s[i] == ')' && topElement != '('){
                    return false; 
                }
                if(s[i] == '}' && topElement != '{'){
                    return false; 
                }
                if(s[i] == ']' && topElement != '['){
                    return false; 
                }
                myStack.pop();
            }
        }
        return myStack.size() == 0; 
    }
};