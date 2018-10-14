
class MyStack {
private:
    queue<int> myQueue; 
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myQueue.push(x); 
        int size = myQueue.size(); 
        while(size > 1){
            int tmp = myQueue.front(); 
            myQueue.pop(); 
            myQueue.push(tmp);
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = myQueue.front(); 
        myQueue.pop(); 
        return top; 
    }
    
    /** Get the top element. */
    int top() {
        return myQueue.front(); 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.size() == 0; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */