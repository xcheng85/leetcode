// different from 32 leetcode
// not continouse substring result

#include <vector>
#include <string>

using namespace std;

// state of each node
struct Node
{
    int maxPairs; 
    int pairs;  // number of pairs in this range
    int open;   // unused (
    int closed; // unused )

    Node()
    {
        maxPairs = pairs = open = closed = 0;
    }
};

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        this->m_size = s.size();
        this->buildTree(s, 0, m_size - 1, 0);
        return numParentnessQuery(0, m_size - 1, 0, m_size - 1, 0).pairs * 2;
    }

  private:
    void buildTree(string &s, int start, int end, int currentIdx)
    {
        if (start == end)
        {
            // leaf node itself: either ( or )
            // since it contains one element, pairs
            m_segmentTree[currentIdx].maxPairs = 0;

            m_segmentTree[currentIdx].pairs = 0;

            // check whether that one element is opening
            // bracket or not
            m_segmentTree[currentIdx].open = (s[start] == '(' ? 1 : 0);

            // check whether that one element is closing
            // bracket or not
            m_segmentTree[currentIdx].closed = (s[start] == ')' ? 1 : 0);

            return;
        }
        else
        {
            int mid = start + (end - start) / 2;
            buildTree(s, start, mid, 2 * currentIdx + 1);
            buildTree(s, mid + 1, end, 2 * currentIdx + 2);

            m_segmentTree[currentIdx] = merge(m_segmentTree[2 * currentIdx + 1], m_segmentTree[2 * currentIdx + 2]);
        }
    }

    // Returns Parent Node after merging its left and right child
    Node merge(const Node &leftChild, const Node &rightChild)
    {
        Node parentNode;
        int minMatched = min(leftChild.open, rightChild.closed);

        parentNode.pairs = leftChild.pairs + rightChild.pairs + minMatched;
        parentNode.open = leftChild.open + rightChild.open - minMatched;
        parentNode.closed = leftChild.closed + rightChild.closed - minMatched;
        return parentNode;
    }

    Node numParentnessQuery(int qs, int qe, int arrayStart, int arrayEnd, int currentIdx) // currentIdx --> node in tree
    {
        Node result;

        if (arrayStart > qe || arrayEnd < qs)
            return result;

        // If segment of this node is a part of given
        // range, then return the node of the segment
        if (qs <= arrayStart && qe >= arrayEnd)
            return m_segmentTree[currentIdx];

        int mid = arrayStart + (arrayEnd - arrayStart) / 2;

        // If a part of this segment overlaps with
        // the given range
        Node leftChild = numParentnessQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);
        Node rightChild = numParentnessQuery(qs, qe, mid+1, arrayEnd, 2 * currentIdx + 2);

        // adds the sum of the left and right
        // segment
        int minMatched = min(leftChild.open, rightChild.closed);

        result.pairs = leftChild.pairs + rightChild.pairs + minMatched;
        result.open = leftChild.open + rightChild.open - minMatched;
        result.closed = leftChild.closed + rightChild.closed - minMatched;

        // returns the value
        return result;
    }

    vector<Node> m_segmentTree;
    int m_size;
};