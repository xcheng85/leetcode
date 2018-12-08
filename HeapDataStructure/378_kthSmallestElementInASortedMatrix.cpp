/* The idea is to use min heap. Following are detailed step.
1) Build a min heap of elements from first row. A heap entry also stores row number and column number.
2) Do following k times.
…a) Get minimum element (or root) from min heap.
…b) Find row number and column number of the minimum element.
…c) Replace root with the next element from same column and min-heapify the root.
3) Return the last extracted root.

Following is C++ implementation of above algorithm. */

#include <vector>
using namespace std;
struct Node
{
    int val;
    int row;
    int col;

    Node(int row, int col, int val) : row(row), col(col), val(val)
    {
    }
};

class cmp
{
  public:
    bool operator()(Node *&p1, Node *&p2)
    {
        return p1->val > p2->val; // min heap
    }
};

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int res;
        if (matrix.size() == 0)
            return 0;

        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int c = 0; c < matrix[0].size(); c++)
        {
            pq.push(new Node(0, c, matrix[0][c]));
        }

        for (int i = 0; i < k; i++)
        {
            Node *minNode = pq.top();
            pq.pop();

            res = minNode->val;

            if (minNode->row + 1 < matrix.size())
            {
                pq.push(new Node(minNode->row + 1, minNode->col, matrix[minNode->row + 1][minNode->col]));
            }
        }

        return res;
    }
};