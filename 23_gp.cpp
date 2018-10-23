/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//1. brutal force
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        vector<int> allValues;

        ListNode *head = NULL;
        ListNode *current = NULL;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *tmp = lists[i];

            while (tmp != NULL)
            {
                allValues.push_back(tmp->val);
                tmp = tmp->next;
            }
        }

        sort(allValues.begin(), allValues.end());

        for (int i = 0; i < allValues.size(); i++)
        {
            if (current == NULL)
            {
                head = new ListNode(allValues[i]);
                current = head;
            }
            else
            {

                current->next = new ListNode(allValues[i]);
                current = current->next;
            }
        }

        return head;
    }
};

//2. one by one
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL;
        ListNode *current = NULL;
        while (true)
        {
            int minVal = INT_MAX;
            int minIdx = 0;
            bool isDone = true;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != NULL)
                {
                    if (lists[i]->val < minVal)
                    {
                        minVal = lists[i]->val;
                        minIdx = i;
                    }
                    isDone = false;
                }
            }

            if (isDone)
                break;
            lists[minIdx] = lists[minIdx]->next;
            if (head == NULL)
            {
                head = new ListNode(minVal);
                current = head;
            }
            else
            {
                current->next = new ListNode(minVal);
                current = current->next;
            }
        }
        return head;
    }
};

//3. priority queue

class Compare
{
public:
    bool operator() (ListNode *lhs, ListNode *rhs) {
        // min on top
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
