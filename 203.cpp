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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode helper(val); 
        helper.next = head; 
        ListNode* prev = &helper;
        ListNode* current = head; 
        while(current != NULL){
            if(current->val == val){
                prev->next = current->next;
                delete current;
                current = current->next; 
            }else{
                prev = current; 
                current = current->next; 
            }
        }
        return helper.next; 
    }
};