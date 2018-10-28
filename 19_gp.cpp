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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); 
        dummy->next = head; 
        
    
        ListNode* faster = dummy;
        for(int i = 0; i <= n; i++)
        {
            faster = faster -> next; 
        }
        
        ListNode* slow = dummy; 
        while(faster != NULL){
            faster = faster->next; 
            slow = slow->next;
        }
        
        if(slow->next)
            slow->next = slow->next->next; 
        
        return dummy->next; 
    }
};