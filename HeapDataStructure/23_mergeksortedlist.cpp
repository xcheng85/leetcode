//1. merge 2 each time, merge k / 2

// merge sorted array is harder, 

// list has extra next pointer to proceeed. 

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Compare
{
  public:
    bool operator()(ListNode *lhs, ListNode *rhs)
    {
        // minimal on top
        return lhs->val > rhs->val;
    }
};

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(0);
        ListNode *current = head;

        std::priority_queue<ListNode *, std::vector<ListNode *>, Compare> q;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
            {
                q.push(lists[i]);
            }
        }

        while (!q.empty())
        {
            //出队列
            current->next = q.top();
            q.pop();
            current = current->next;
            //判断当前链表是否为空，不为空就将新元素入队
            ListNode *next = current->next;
            if (next != NULL)
            {
                q.push(next);
            }
        }
        return head->next;
    }
};
