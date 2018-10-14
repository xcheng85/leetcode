class MinStack {
public:
    /** initialize your data structure here. */
    struct ListNode{
       int val;
       int minval; // key record
       ListNode* next; 
       ListNode(int val, int minval): val(val), next(NULL), minval(minval){
           
       }
    }; 
    
    MinStack() {
        this->m_header = new ListNode(INT_MAX, INT_MAX); 
    }
    
    ~MinStack() {
         
    }
    
    void push(int x) {
        int newmin = this->m_header->next == NULL ? x : min(x, this->m_header->next->minval);
        ListNode* newNode = new ListNode(x, newmin);
        ListNode* tmp = this->m_header->next; 
        this->m_header->next = newNode; 
        newNode->next = tmp; 
    }
    
    void pop() {
        ListNode* tmp = this->m_header->next;
        this->m_header->next = this->m_header->next->next;
        delete tmp; 
    }
    
    int top() {
        return this->m_header->next->val; 
    }
    
    int getMin() {
        return this->m_header->next->minval;
    }
    
private: 
    ListNode* m_header; 
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */