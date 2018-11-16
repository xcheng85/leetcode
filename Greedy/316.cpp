class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> myStack; 
        vector<int> count(26, 0); // left over after a certion position
        
        for(auto c:s){
            count[c - 'a']++;
        }
        
        // visited up to current position
        vector<bool> visited(26, false);
        
        for(auto c: s){
            count[c - 'a']--; 
            if(visited[c - 'a'])
                continue; // already have a better order
            while(!myStack.empty() && myStack.top() > c && count[myStack.top() - 'a'] > 0){
                // stack.top() has leftover after current pos. can pop
                visited[myStack.top() - 'a'] = false; 
                myStack.pop(); 
            }
            myStack.push(c);
            visited[c - 'a'] = true; 
        }
        
        // the order in the stack is the final result
        string ans; 
        ans.resize(myStack.size()); 
        int pos = myStack.size() - 1; 
        while(!myStack.empty()){
            ans[pos--] = myStack.top(); 
            myStack.pop(); 
        }
        
        return ans; 
    }
};
