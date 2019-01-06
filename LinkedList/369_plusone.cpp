/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *plusOne(ListNode *head)
    {
        if (!head)
            return head;
            
        ListNode *curr = head, *lessNode = NULL;
        while (curr)
        {
            if (curr->val < 9)
                lessNode = curr;
            curr = curr->next;
        }
        if (lessNode)
        {
            lessNode->val++;
            while (lessNode->next)
            {
                lessNode->next->val = 0;
                lessNode = lessNode->next;
            }
            return head;
        }
        else
        {
            ListNode *newNode = new ListNode(1);
            newNode->next = head;
            while (head)
            {
                head->val = 0;
                head = head->next;
            }
            return newNode;
        }
    }
};