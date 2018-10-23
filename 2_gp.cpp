/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int fromPreviousBit = 0; 
        
        ListNode* curr1 = l1; 
        ListNode* curr2 = l2; 
        ListNode* head = new ListNode(0); 
        ListNode* current = head; 
    
        while(curr1 != NULL && curr2 != NULL){
            int val = (curr1->val + curr2->val + fromPreviousBit) % 10; 
            fromPreviousBit = (curr1->val + curr2->val + fromPreviousBit) / 10; 
            
            current->next = new ListNode(val); 
            current = current->next; 
            
            curr1 = curr1->next; 
            curr2 = curr2->next; 
        }
        
        ListNode* curr = curr1 == NULL ? curr2 : curr1; 
        
        while(curr != NULL){
            int val = (curr->val + fromPreviousBit) % 10; 
            fromPreviousBit = (curr->val + fromPreviousBit) / 10; 
            current->next = new ListNode(val); 
            current = current->next; 
            curr = curr->next; 
        }
        
        if(fromPreviousBit > 0){
            current->next = new ListNode(fromPreviousBit); 
        }
        
        
        return head->next; 
    }
};