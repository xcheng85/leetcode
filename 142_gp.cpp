/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// hashset
class Solution
{
  public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> cache;

        ListNode *current = head;

        while (current != NULL)
        {
            if (cache.find(current) != cache.end())
            {
                return current;
            }
            else
            {
                cache.insert(current);
                current = current->next;
            }
        }

        return NULL;
    }
};

// two pointer
class Solution
{
  public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        ListNode *intersection = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                intersection = fast;
                break; 
            }
        }

        if(intersection == NULL)
            return NULL; 

        ListNode *current = head; 

        while(current != intersection){
            current = current -> next; 
            intersection = intersection -> next; 
        }

        return current; 
    }
};