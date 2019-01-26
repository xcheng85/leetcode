/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i>=0; i--) {
            myStack.push(nestedList[i]);
        }
    }

    int next() {
        int val = myStack.top().getInteger();       
        myStack.pop();
        return val;
    }

    bool hasNext() {
        while(true){
            if(myStack.size() == 0)
                return false; 
            if (myStack.top().isInteger())
                return true;
            
            NestedInteger current = myStack.top(); 
            myStack.pop(); 
            
            for(int i = current.getList().size() - 1; i >= 0; i--){
                myStack.push(current.getList()[i]);
            }
        }        
        return false;
    }
    
private:
    stack<NestedInteger> myStack; 
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */