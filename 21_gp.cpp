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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1; 
        ListNode* curr2 = l2; 
        ListNode* curr = NULL; 
        ListNode* header = NULL; 
        while(curr1 != NULL && curr2 != NULL){
            ListNode* newNode; 
            if(curr1->val <= curr2->val){
                newNode = new ListNode(curr1->val);
                curr1 = curr1->next;
            }else{
                newNode = new ListNode(curr2->val);
                curr2 = curr2->next;
            }
            if(curr == NULL){
                curr = newNode;
                header = curr; 
            }else{
                curr->next = newNode;
                curr = newNode; 
            }
        }
        curr1 = curr1 != NULL ? curr1 : curr2; 
        while(curr1 != NULL){
            if(curr == NULL){
                curr = new ListNode(curr1->val);
                header = curr; 
            }else{
                ListNode* newNode = new ListNode(curr1->val);
                curr->next = newNode;
                curr = newNode; 
            }
            curr1 = curr1->next; 
            
        }
        return header; 
    }
};