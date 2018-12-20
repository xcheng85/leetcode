// only lowercase
/* aab"
Output: "aba" */

// like like merge sort from k sorted list
//a : [0] b : [1] b -> 1

#include <string>
using namespace std;

struct Node
{
    int frequency; //
    char alpha;

    Node(char a, int f) : alpha(a), frequency(f)
    {
    }
};

class cmp
{
  public:
    bool operator()(Node &p1, Node &p2)
    {
        return p1.frequency < p2.frequency || (p1.frequency == p2.frequency && p1.alpha > p2.alpha); // respect frequency
    }
};

class Solution
{
  public:
    string reorganizeString(string S)
    {
        // step one frequency statistics
        vector<int> count(26, 0);
        for (auto &c : S)
        {
            count[c - 'a']++;
        }

        priority_queue<Node, vector<Node>, cmp> pq;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                pq.push(Node(i + 'a', count[i]));
            }
        }

        Node prev('#', 0);
        string ans;
        // traverse queue
        while (!pq.empty())
        {
            // pop top element from queue and add it
            // to string.
            Node k = pq.top();
            pq.pop(); // k.alpha cannot be participat in the next charactor
            ans.push_back(k.alpha);

            // IF frequency of previous character is less
            // than zero that means it is useless, we
            // need not to push it
            if (prev.frequency > 0)
                pq.push(prev);

            // make current character as the previous 'char'
            // decrease frequency by 'one'
            (k.frequency)--;
            prev = k;
        }

        if (ans.size() != S.size())
            return "";

        return ans;
    }
};